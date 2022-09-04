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

#define N 102

int a[N], f[N][N];

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n = rd();
    for(int i = 0; i < n; ++i) {
        a[i] = rd();
    }
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int ft = f[i][j];
            if(ft == 0x3f3f3f3f) {
                continue;
            }
            int C = 0;
            for(int k = i; k < n; ++k) {
                if(a[k] != k - i) {
                    ++C;
                }
                f[k + 1][j + 1] = min(f[k + 1][j + 1], ft + C);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(i != 1) {
            putchar('\n');
        }
        wr(f[n][i]);
    }
    return 0;
}

