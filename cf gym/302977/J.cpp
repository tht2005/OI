#include <bits/stdc++.h>
using namespace std;

const int nmax = 100010;
const int md = 1000000007;
int n, m, k, x, res, dp[nmax][3][11], dp2[3][11];
vector<int>adj[nmax];

inline void add(int& a, int b)
{
    if((a += b) >= md) a -= md;
}

inline int mul(int a, int b)
{
    return 1ll * a * b % md;
}

void dfs(int u, int p)
{
    for(int t = 0; t < 3; ++t)
        for(int cnt = 0; cnt <= x; ++cnt)
            dp[u][t][cnt] = 0;
    dp[u][0][0] = k - 1;
    dp[u][1][1] = 1;
    dp[u][2][0] = m - k;
    for(int v: adj[u]) if(v ^ p) {
        dfs(v, u);
        for(int t = 0; t < 3; ++t)
            for(int cnt = 0; cnt <= x; ++cnt)
                dp2[t][cnt] = 0;
        for(int cnt = 0; cnt <= x; ++cnt){
            for(int cnt2 = 0; cnt + cnt2 <= x; ++cnt2){
                for(int t = 0; t < 3; ++t) add(dp2[0][cnt + cnt2], mul(dp[u][0][cnt], dp[v][t][cnt2]));
                add(dp2[1][cnt + cnt2], mul(dp[u][1][cnt], dp[v][0][cnt2]));
                for(int t = 0; t < 3; ++t) if(t ^ 1){
                    add(dp2[2][cnt + cnt2], mul(dp[u][2][cnt], dp[v][t][cnt2]));
                }
            }
        }
        for(int t = 0; t < 3; ++t)
            for(int cnt = 0; cnt <= x; ++cnt)
                dp[u][t][cnt] = dp2[t][cnt];
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int _ = 0; _ + 1 < n; ++_){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> k >> x;
    dfs(1, -1);
    res = 0;
    for(int j = 0; j <= x; ++j){
        add(res, dp[1][0][j]);
        add(res, dp[1][1][j]);
        add(res, dp[1][2][j]);
    }
    cout << res;
    return 0;
}
