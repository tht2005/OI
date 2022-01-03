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

int a[4][4], b[4][4];

void pray_for_AC() {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            char c = getchar(); while(c != 'b' && c != 'w') c = getchar();
            a[i][j] = (c == 'b');
        }
    }
    int res = 17;
    for(int t = 0; t < 1 << 16; ++t) {
        memcpy(b, a, sizeof(b));
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                if(t >> (4 * i + j) & 1) {
                    b[i][j] ^= 1;
                    if(i) b[i - 1][j] ^= 1;
                    if(i < 3) b[i + 1][j] ^= 1;
                    if(j) b[i][j - 1] ^= 1;
                    if(j < 3) b[i][j + 1] ^= 1;
                }
            }
        }
        bool f = 1;
        for(int i = 0; i < 4 && f; ++i) {
            for(int j = 0; j < 4; ++j) {
                if(b[0][0] ^ b[i][j]) {
                    f = 0;
                    break;
                }
            }
        }
        if(f) res = min(res, __builtin_popcount(t));
    }
    if(res > 16) puts("Impossible");
    else wr(res);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
