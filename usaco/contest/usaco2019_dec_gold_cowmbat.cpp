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

#define N 100005

int a[N], C[26][26], S[26][N], val[26][N], f[N];

int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    int n = rd(), m = rd(), kk = rd();
    char ch = getchar();
    while(ch < 'a' || ch > 'z') {
        ch = getchar();
    }
    for(int i = 0; i < n; ++i) {
        a[i] = ch - 'a';
        ch = getchar();
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            C[i][j] = rd();
        }
    }
    for(int k = 0; k < m; ++k) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            S[j][i + 1] = S[j][i] + C[a[i]][j];
            if(i + 1 >= kk) {
                f[i + 1] = min(f[i + 1], S[j][i + 1] + val[j][i + 1 - kk]);
            }
        }
        for(int j = 0; j < m; ++j) {
            val[j][i + 1] = min(val[j][i], f[i + 1] - S[j][i + 1]);
        }
    }
    wr(f[n]);
    return 0;
}

