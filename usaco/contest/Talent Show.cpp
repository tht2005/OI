#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, W; cin >> n >> W;
    vector<pair<int, int>> a(n);
    for(auto& [w, t]: a)
        cin >> w >> t;
    double l = 0, r = 2021;
    while(r - l > 1e-5) {
        double m = (l + r) * .5;
        vector<double> dp(W + 1, -1e100); dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            double val = a[i].second - m * a[i].first;
            for(int j = W; j >= 0; --j) {
                if(a[i].first + j >= W) {
                    dp[W] = max(dp[W], dp[j] + val);
                }
                else {
                    dp[a[i].first + j] = max(dp[a[i].first + j], dp[j] + val);
                }
            }
        }
        if(dp[W] >= 0) l = m; else r = m;
    }
    cout << (int)((l + r) * .5 * 1000);
    return 0;
}
