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

#define LL long long

#define N 102
#define K 10

int a[N];
LL f[N][K];

int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    int n = rd(), kk = rd();
    for(int i = 0; i < n; ++i) {
        a[i] = rd();
    }
    LL res = 1LL << 60;
    for(int t = n; t--; ) {
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < kk; ++j) {
                LL ft = f[i][j];
                if(ft == 0x3f3f3f3f3f3f3f3f) {
                    continue;
                }
                LL C = 0;
                for(int k = i; k < n; ++k) {
                    C += (LL)(k - i) * a[k];
                    f[k + 1][j + 1] = min(f[k + 1][j + 1], ft + C);
                }
            }
        }
        for(int i = 1; i <= kk; ++i) {
            res = min(res, f[n][i]);
        }
        a[n] = a[0];
        for(int i = 0; i < n; ++i) {
            a[i] = a[i + 1];
        }
    }
    printf("%lld", res);
    return 0;
}

