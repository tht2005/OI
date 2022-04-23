#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;
const int K = 202;

LL div_(LL a, LL b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

struct line_t {
    LL k, m;
    int i;
    line_t() {}
    line_t(LL k_, LL m_, int i_) : k(k_), m(m_), i(i_) {}
    LL operator() (LL x) const {
        return k * x + m;
    }
};
struct cht {
    int n, p;
    line_t L[N];
    void init() {
        n = p = 0;
    }
    bool bad(const line_t& a, const line_t& b, const line_t& c) {
        if(b.k == c.k) return b.m >= c.m;
        return div_(b.m - a.m, a.k - b.k) >= div_(c.m - b.m, b.k - c.k);
    }
    void insert(LL k, LL m, int i) {
        line_t nw(k, m, i);
        while(n > 1 && bad(L[n - 2], L[n - 1], nw)) --n;
        if(n == 0 || L[n - 1].k != nw.k) L[n++] = nw;
    }
    line_t query(LL x) {
        while(p + 1 < n && L[p](x) > L[p + 1](x)) ++p;
        return L[p];
    }
} S;

int n, kk, s[N], trc[K][N];
LL f[N], g[N];

int main() {
    scanf("%d %d", &n, &kk);
    for(int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        s[i] = s[i - 1] + a;
    }
    memset(f, 0, sizeof(f));
    for(int t = 1; t <= kk; ++t) {
        memcpy(g, f, sizeof(g));
        memset(f, 0, sizeof(f));
        S.init();
        for(int i = t + 1; i <= n; ++i) {
            S.insert(-s[i - 1], (LL)s[i - 1] * s[i - 1] - g[i - 1], i - 1);
            line_t tmp = S.query(s[i]);
            f[i] = -tmp(s[i]);
            trc[t][i] = tmp.i;
        }
    }
    printf("%lld\n", f[n]);
    for(int i = n; (i = trc[kk--][i]); ) {
        printf("%d ", i);
    }
    return 0;
}
