#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, T; cin >> n >> m >> T;
    vector<int>deg(n, 0);
    vector<vector<pair<int, int>>>adj(n);
    while(m --> 0){
        int u, v, w; cin >> u >> v >> w;
        adj[u - 1].push_back({w, v - 1});
        ++deg[v - 1];
    }
    vector<int>tp;
    queue<int> q;
    for(int i = 0; i < n; ++i)if(!deg[i])q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        tp.push_back(u);
        for(auto [w, v]: adj[u]) if(--deg[v] == 0) q.push(v);
    }
    reverse(tp.begin(), tp.end());
    vector<vector<int>> dp(n, vector<int>(n, inf));
    dp[n - 1][0] = 0;
    for(int u: tp){
        for(auto [w, v]: adj[u]){
            for(int i = 0; i + 1 < n; ++i)if(dp[v][i] ^ inf){
                if(dp[v][i] + w <= T)
                    dp[u][i + 1] = min(dp[u][i + 1], dp[v][i] + w);
            }
        }
    }
    int s = 0, l = 0;
    for(int i = n - 1; i >= 0; --i)if(dp[s][i] <= T){
        l = i;
        break;
    }
    cout << l + 1 << '\n';
    for(;; --l){
        cout << s + 1 << ' ';
        if(!l)break;
        for(auto [w, u]: adj[s]){
            if(dp[s][l] == dp[u][l - 1] + w){
                s = u;
                break;
            }
        }
    }
    return 0;
}
