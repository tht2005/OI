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

void pray_for_AC() {
    int n = rd(), s = rd();
    int t = 0, f = 0;
    for(int i = 1; i <= n; ++i) {
        t += rd();
        if(t - i > f + s) {
            puts("NO");
            return;
        }
        f = min(f, t - i);
    }
    puts("YES");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
