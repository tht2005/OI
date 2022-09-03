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

#define N 402

LL s[N], f[N][N];

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    int n = rd(), kk = rd();
    s[0] = 0;
    for(int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + rd();
    }
    memset(f, 0x3f, sizeof(f));
    LL MX = -1;
    for(int i = 1; i <= n; ++i) {
        MX = max(MX, s[i] - s[i - 1]);
        f[i][0] = i * MX - s[i];
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= i && j < kk; ++j) {
            LL ft = f[i][j];
            if(ft == 0x3f3f3f3f3f3f3f3f) {
                continue;
            }
            MX = -1;
            for(int k = i + 1; k <= n; ++k) {
                MX = max(MX, s[k] - s[k - 1]);
                f[k][j + 1] = min(f[k][j + 1], ft + (k - i) * MX - (s[k] - s[i]));
            }
        }
    }
    printf("%lld", *min_element(f[n], f[n] + 1 + kk));
    return 0;
}

