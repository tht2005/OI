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

#define md 1000000007
void add(int& a, int b) {
    a += b;
    if(a >= md) {
        a -= md;
    }
    if(a < 0) {
        a += md;
    }
}

#define N 102

int H[N], f[N][1003];

int main() {
    int n = rd();
    for(int i = 0; i < n; ++i) {
        H[i] = rd();
    }
    if(n & 1) {
        long long res = 0;
        int t = *min_element(H, H + n) + 1;
        while(t--) {
            for(int i = 0; i <= 1000; ++i) {
                f[1][i] = (i > H[0]) ? (H[0] + 1) : (i + 1);
            }
            for(int i = 1; i < n; ++i) {
                for(int j = 0; j <= 1000; ++j) {
                    f[i + 1][j] = (j == 0) ? 0 : f[i + 1][j - 1];
                    if(j <= H[i]) {
                        add(f[i + 1][j], f[i][H[i] - j]);
                    }
                }
            }
            res += f[n][0];
            for(int i = 0; i < n; ++i) {
                --H[i];
            }
        }
        wr(res % md);
    }
    else {
        for(int i = 0; i <= 1000; ++i) {
            f[1][i] = (i > H[0]) ? (H[0] + 1) : (i + 1);
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j <= 1000; ++j) {
                f[i + 1][j] = (j == 0) ? 0 : f[i + 1][j - 1];
                if(j <= H[i]) {
                    add(f[i + 1][j], f[i][H[i] - j]);
                }
            }
        }
        wr(f[n][0]);
    }
    return 0;
}

