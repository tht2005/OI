#include <bits/stdc++.h>

using namespace std;

int rd() {
    bool neg = 0; char c = getchar(); for(; c < '0' || c > '9'; c = getchar()) if(c == '-') neg = !neg;
    int n = 0; while('0' <= c && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = getchar();
    return neg ? -n : n;
}
void wr(int n) {
    static char o[11];
    if(n < 0) putchar('-'), n = -n;
    int i = 0; do o[i++] = n % 10 + '0'; while(n /= 10);
    while(i--) putchar(o[i]);
}

void pray_for_AC() {
    int n = rd();
    vector<int> a(n), s(1 << n);
    for(int i = 0; i < n; ++i)
        a[i] = s[1 << i] = rd();
    vector<int> dp(1 << n, 1000000000);
    dp[0] = 0;
    for(int t = 1; t < 1 << n; ++t) {
        if(int w = t & t - 1) {
            s[t] = s[w] + s[t ^ w];
        }
        for(int i = 0; i < n; ++i) {
            int nt = t, d = s[t];
            for(int j = 0; j < 3; ++j) {
                int k = (i + j) % n;
                if(nt >> k & 1) {
                    nt ^= 1 << k;
                    d -= a[k];
                }
            }
            dp[t] = min(dp[t], dp[nt] + d);
        }
    }
    wr(dp.back());
}

int main() {
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
