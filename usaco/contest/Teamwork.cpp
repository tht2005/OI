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

#define N 10000

int a[N], f[N];

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int n = rd(), k = rd();
    for(int i = 0, x; i < n; ++i) {
        scanf("%d", a + i);
        f[i] = x = -1;
        for(int j = i; j >= 0 && j > i - k; --j) {
            x = max(x, a[j]);
            f[i] = max(f[i], (j ? f[j - 1] : 0) + (i + 1 - j) * x);
        }
    }
    printf("%d", f[n - 1]);
    return 0;
}

