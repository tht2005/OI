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

typedef long long LL;

const int N = 501;
LL dp[N][N];

void pray_for_AC() {
    int n = rd();
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            LL ft = dp[i][j];
            if(!ft) continue;
            for(int k = j + 1; i + k <= n; ++k)
                dp[i + k][k] += ft;
        }
    }
    LL res = 0;
    for(int i = 0; i < n; ++i)
        res += dp[n][i];
    printf("%lld", res);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
