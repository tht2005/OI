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
    int n = rd();
    vector<double> e(n, 0), p(1 << n, 0);
    p[0] = 1;
    for(int t = 0; t + 1 < 1 << n; ++t) {
        int f = 0;
        while(t >> f & 1) ++f;
        e[__builtin_popcount(t)] += f * p[t];
        for(int i = n; i--; ) {
            if(!(t >> i & 1)) f = i;
            p[t | 1 << f] += p[t] / n;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(i) putchar('\n');
        printf("%.6lf", e[i]);
    }
}

int main() {
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
