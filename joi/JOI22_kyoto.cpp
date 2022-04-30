#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct dt {
    LL n, d;
    int i;
    bool t;
    bool operator< (const dt& B) const {
        return n * B.d > B.n * d;
    }
};

const int N = 100005;
int n, m, cnt, a[N], b[N], x[N], y[N];
LL res;
multiset<dt> S;
multiset<dt>::iterator z[N], t[N];
set<int> c, d;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", b + i);
    }
    for(int i = 1; i < n; ++i) {
        z[i] = S.insert({ a[i] - a[i - 1], 1, i, 0 });
        c.insert(i);
    }
    for(int i = 1; i < m; ++i) {
        t[i] = S.insert({ b[i] - b[i - 1], 1, i, 1 });
        d.insert(i);
    }
    while(!S.empty()) {
        auto [nn, dd, i, _] = *S.begin();
        S.erase(S.begin());
        if(_) {
            auto it = d.erase(d.find(i));
            if(it != d.end()) {
                int j = *it;
                dt tmp = *t[j];
                S.erase(t[j]);
                tmp.n += nn;
                tmp.d += dd;
                t[j] = S.insert(tmp);
            }
            y[i] = cnt++;
        }
        else {
            auto it = c.erase(c.find(i));
            if(it != c.end()) {
                int j = *it;
                dt tmp = *z[j];
                S.erase(z[j]);
                tmp.n += nn;
                tmp.d += dd;
                z[j] = S.insert(tmp);
            }
            x[i] = cnt++;
        }
    }
    res = 0;
    for(int i = n - 1, j = m - 1; i || j; ) {
        if(i == 0) {
            res += a[0];
            --j;
        }
        else if(j == 0) {
            res += b[0];
            --i;
        }
        else if(x[i] < y[j]) {
            res += b[j];
            --i;
        }
        else {
            res += a[i];
            --j;
        }
    }
    printf("%lld", res);
    return 0;
}
