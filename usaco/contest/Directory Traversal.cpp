#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const int nmax = 100010;
int n, len[nmax], leaf[nmax], w[nmax], w2[nmax];
ll dp[nmax], dp2[nmax];
vector<int> adj[nmax];
char s[20];

void dfs(int u)
{
    dp[u] = 0;
    if(adj[u].empty()) {
        leaf[u] = 1;
        w[u] = 1;
    }
    else {
        leaf[u] = 0;
        w[u] = 0;
        for(int v: adj[u]) {
            dfs(v);
            dp[u] += dp[v] + w[v] * (len[v] + (leaf[v] ^ 1));
            w[u] += w[v];
        }
    }
}

void dfs2(int u)
{
    for(int v: adj[u]) {
        w2[v] = w2[u] + w[u] - w[v];
        dp2[v] = dp2[u] + 3 * w2[v] + dp[u] - dp[v] - w[v] * (len[v] + (leaf[v] ^ 1));
        dfs2(v);
    }
}

int main()
{
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int sz;
        scanf("%s %d", s, &sz);
        len[i] = strlen(s);
        while(sz --> 0) {
            int c; scanf("%d", &c);
            adj[i].push_back(c);
        }
    }
    dfs(1);
    dfs2(1);
    ll res = inf;
    for(int i = 1; i <= n; ++i) if(!leaf[i])
        res = min(res, dp[i] + dp2[i]);
    printf("%lld", res);
    return 0;
}
