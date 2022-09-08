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

#define N 1000006

int f[N], g[N];

int main() {
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    int n = rd(), m = rd(), k = rd();
    f[0] = 1;
    g[0] = 0;
    for(int i = 1; i <= n; ++i) {
        long long val = (f[i - 1] + (long long)(f[i - 1] - ((i < k) ? 0 : f[i - k])) * (m - 1) + 1) % md;
        if(val < 0) {
            val += md;
        }
        f[i] = val;
        val = g[i - 1] + (long long)g[i - 1] * (m - 1);
        if(i >= k) {
            val += f[i - k];
        }
        if(i > k) {
            val -= f[i - 1 - k];
        }
        val %= md;
        if(val < 0) {
            val += md;
        }
        g[i] = val;
    }
    int res = ((long long)(g[n] - g[n - 1]) * m) % md;
    if(res < 0) {
        res += md;
    }
    wr(res);
    return 0;
}

