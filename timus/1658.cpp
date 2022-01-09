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

bool ckmin(int8_t& a, int8_t b) {
    return a > b ? a = b, 1 : 0;
}

int8_t dp[901][8101], trc[901][8101];

int main() {
    dp[0][0] = 0;
    for(int i = 0; i < 901; ++i) {
        for(int j = (i == 0); j < 8101; ++j) {
            dp[i][j] = 101;
            for(int c = 1; c < 10 && c <= i && c * c <= j; ++c)
                if(ckmin(dp[i][j], dp[i - c][j - c * c] + 1))
                    trc[i][j] = c;
        }
    }
    int q = rd();
    while(q--) {
        int s1 = rd(), s2 = rd();
        if(s1 < 901 && s2 < 8101 && dp[s1][s2] < 101) {
            while(s1 && s2) {
                int c = trc[s1][s2];
                putchar(c + '0');
                s1 -= c;
                s2 -= c * c;
            }
            putchar('\n');
        }
        else {
            puts("No solution");
        }
    }
    return 0;
}
