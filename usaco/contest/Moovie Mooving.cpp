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

#define N 20
int d[N], f[1 << N];
vector<int> start[N];

int main() {
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    int n = rd(), L = rd();
    for(int i = 0, c; i < n; ++i) {
        d[i] = rd();
        c = rd();
        while(c--) {
            start[i].push_back(rd());
        }
    }
    memset(f, 0xff, sizeof(f));
    f[0] = 0;
    for(int t = 0; t < 1 << n; ++t) {
        int ft = f[t];
        if(ft == -1) {
            continue;
        }
        for(int i = 0; i < n; ++i) {
            if(t >> i & 1) {
                continue;
            }
            auto it = upper_bound(start[i].begin(), start[i].end(), ft);
            if(it == start[i].begin()) {
                continue;
            }
            --it;
            if((*it) + d[i] < ft) {
                continue;
            }
            f[t | (1 << i)] = max(f[t | (1 << i)], (*it) + d[i]);
        }
    }
    if(f[(1 << n) - 1] < L) {
        puts("-1");
        return 0;
    }
    int res = n;
    for(int t = 0; t < 1 << n; ++t) {
        if(f[t] >= L) {
            res = min(res, __builtin_popcount(t));
        }
    }
    wr(res);
    return 0;
}
