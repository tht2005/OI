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

#define md 1000000009

#define N 1003

int a[N], b[N], f[11][N][N];

int main() {
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    int n = rd(), m = rd(), kk = rd();
    for(int i = 1; i <= n; ++i) {
        a[i] = rd();
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= m; ++i) {
        b[i] = rd();
    }
    sort(b + 1, b + 1 + m);
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            f[0][i][j] = 1;
        }
    }
    for(int k = 1; k <= kk; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                long long s = (long long)f[k][i - 1][j] + f[k][i][j - 1] - f[k][i - 1][j - 1];
                if(a[i] > b[j]) {
                    s += f[k - 1][i - 1][j - 1];
                }
                s %= md;
                if(s < 0) {
                    s += md;
                }
                f[k][i][j] = s;
            }
        }
    }
    wr(f[kk][n][m]);
    return 0;
}

