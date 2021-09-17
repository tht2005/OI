#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int m, a, b; cin >> m >> a >> b;
    bitset<5000001> dp, dp2;
    dp[0] = dp2[0] = 1;
    for(int i = 1; i <= m; ++i) {
        if(i >= a && dp[i - a]) dp[i] = 1;
        if(i >= b && dp[i - b]) dp[i] = 1;
        if(dp[i]) {
            dp2[i >> 1] = 1;
        }
    }
    for(int i = 1; i <= m; ++i) {
        if(i >= a && dp2[i - a]) dp2[i] = 1;
        if(i >= b && dp2[i - b]) dp2[i] = 1;
    }
    for(int i = m; i >= 0; --i) {
        if(dp2[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}
