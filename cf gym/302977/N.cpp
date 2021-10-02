#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> a[i][j];
    vector<vector<int>>mn(n, vector<int>(n, inf)), mn2(n, vector<int>(n, inf));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int x = 0; x < m; ++x)mn[i][j] = min(mn[i][j], abs(a[i][x] - a[j][x]));
            for(int x = 0; x + 1 < m; ++x)mn2[i][j] = min(mn2[i][j], abs(a[i][x] - a[j][x + 1]));
        }
    }
    int res = 0;
    for(int s = 0; s < n; ++s){
        vector<vector<int>>dp(n, vector<int>(1 << n, 0));
        dp[s][1 << s] = inf;
        for(int mask = 0; mask < (1 << n); ++mask){
            if(__builtin_popcount(mask) < 2) continue;
            for(int i = 0; i < n; ++i) if(mask >> i & 1){
                for(int j = 0; j < n; ++j) if(i ^ j && (mask >> j & 1) && dp[j][mask ^ (1 << i)]){
                    dp[i][mask] = max(dp[i][mask], min(dp[j][mask ^ (1 << i)], mn[j][i]));
                }
            }
        }
        for(int i = 0; i < n; ++i){
            res = max(res, min(dp[i][(1 << n) - 1], mn2[i][s]));
        }
    }
    cout << res;
    return 0;
}
