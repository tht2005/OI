#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

struct sgt {
    int st[N << 2];
    sgt() {
        memset(st, 0, sizeof(st));
    }
    void build(int x, int l, int r, int* a) {
        if(l == r) {
            st[x] = a[l];
        }
        else {
            int m = (l + r) >> 1;
            build(x << 1, l, m, a);
            build(x << 1 | 1, m + 1, r, a);
            st[x] = max(st[x << 1], st[x << 1 | 1]);
        }
    }
    void update(int x, int l, int r, int i, int d) {
        if(l == r) {
            if(st[x] < d) {
                st[x] = d;
            }
        }
        else {
            int m = (l + r) >> 1;
            if(i > m) update(x << 1 | 1, m + 1, r, i, d);
            else update(x << 1, l, m, i, d);
            st[x] = max(st[x << 1], st[x << 1 | 1]);
        }
    }
    int query(int x, int l, int r, int ql, int qr) {
        if(r < ql || qr < l) return 0;
        if(ql <= l && r <= qr) return st[x];
        int m = (l + r) >> 1;
        return max(query(x << 1, l, m, ql, qr), query(x << 1 | 1, m + 1, r, ql, qr));
    }
    int bs(int x, int l, int r, int ql, int qr, int d) {
        if(r < ql || qr < l || st[x] < d) return 0;
        if(l == r) return l;
        int m = (l + r) >> 1;
        if(ql <= l && r <= qr) {
            if(st[x << 1 | 1] >= d) return bs(x << 1 | 1, m + 1, r, ql, qr, d);
            return bs(x << 1, l, m, ql, qr, d);
        }
        int _ = bs(x << 1 | 1, m + 1, r, ql, qr, d);
        return _ ? _ : bs(x << 1, l, m, ql, qr, d);
    }
} f, g;

int n, d, a[N], b[N], idx[N];
deque<int> _;

int main() {
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < n; ++i) {
        while(!_.empty() && a[i] < _.back()) _.pop_back();
        _.push_back(a[i]);
        if(i + 1 >= d) {
            b[i - d + 1] = _.front();
            if(_.front() == a[i - d + 1]) _.pop_front();
        }
    }
    for(int i = n - d + 1; i < n; ++i) {
        b[i] = 2e9;
    }
    g.build(1, 0, n - 1, b);
    iota(idx, idx + n, 0);
    sort(idx, idx + n, [&](int i, int j) {
        if(a[i] != a[j]) return a[i] < a[j];
        return i > j;
    });
    for(int x = 0; x < n; ++x) {
        int i = idx[x], L = (i < d) ? 0 : g.bs(1, 0, n - 1, 0, i - d, a[i]);
        f.update(1, 0, n - 1, i, (i ? f.query(1, 0, n - 1, L, i - 1) : 0) + 1);
    }
    printf("%d", f.st[1]);
    return 0;
}
