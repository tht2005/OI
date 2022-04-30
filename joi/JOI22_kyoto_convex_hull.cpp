#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct pt {
    int x, y;
    pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

bool ccw(const pt& a, const pt& b, const pt& c) {
    return (LL)(b.x - a.x) * (c.y - b.y) - (LL)(c.x - b.x) * (b.y - a.y) > 0;
}

const int N = 100005;
int n, m, n1, n2, a[N], b[N];
double x[N], y[N];
LL res;
pt l1[N], l2[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        pt nw(i, a[i]);
        while(n1 > 1 && !ccw(l1[n1 - 2], l1[n1 - 1], nw)) --n1;
        l1[n1++] = nw;
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", b + i);
        pt nw(i, b[i]);
        while(n2 > 1 && !ccw(l2[n2 - 2], l2[n2 - 1], nw)) --n2;
        l2[n2++] = nw;
    }
    x[0] = -1e18;
    for(int i = 1; i < n1; ++i) {
        x[i] = (double)(l1[i].y - l1[i - 1].y) / (l1[i].x - l1[i - 1].x);
    }
    y[0] = -1e18;
    for(int i = 1; i < n2; ++i) {
        y[i] = (double)(l2[i].y - l2[i - 1].y) / (l2[i].x - l2[i - 1].x);
    }
    for(int i = n1 - 1, j = n2 - 1; i || j; ) {
        if(x[i] > y[j]) {
            res += (LL)l2[j].y * (l1[i].x - l1[i - 1].x);
            --i;
        }
        else {
            res += (LL)l1[i].y * (l2[j].x - l2[j - 1].x);
            --j;
        }
    }
    printf("%lld", res);
    return 0;
}
