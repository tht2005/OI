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

const int N = 100;
int n, a[N][N], h[N];

void pray_for_AC() {
    n = rd();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            a[i][j] = rd();
    int res = numeric_limits<int>::min();
    for(int i = 0; i < n; ++i) {
        memset(h, 0, n * sizeof *h);
        for(int j = i; j < n; ++j) {
            int dp = 0;
            for(int k = 0; k < n; ++k) {
                h[k] += a[j][k];
                dp = max(dp + h[k], h[k]);
                res = max(res, dp);
            }
        }
    }
    wr(res);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
