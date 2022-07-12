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

struct dt {
    int f, s, i;
    bool operator== (const dt& b) const {
        return (f == b.f) && (s == b.s);
    }
    bool operator< (const dt& b) const {
        if(f != b.f) {
            return f < b.f;
        }
        return s < b.s;
    }
};

#define N 2003
int res1[N], res2[N];
dt a[N];

bool cmp(const dt& L, int x, const dt& R, int y, bool equal_case) {
    static int c[4], d[4];
    c[0] = L.f;
    c[1] = L.s;
    c[2] = x;
    sort(c, c + 3, greater<int> ());
    bool cont;
    do {
        cont = 0;
        for(int i = 0; i < 2; ++i) {
            if(c[i] && c[i] == c[i + 1]) {
                ++c[i];
                c[i + 1] = 0;
                cont = 1;
                sort(c, c + 3, greater<int> ());
                break;
            }
        }
    } while(cont);
    d[0] = R.f;
    d[1] = R.s;
    d[2] = y;
    sort(d, d + 3, greater<int> ());
    do {
        cont = 0;
        for(int i = 0; i < 2; ++i) {
            if(d[i] && d[i] == d[i + 1]) {
                ++d[i];
                d[i + 1] = 0;
                cont = 1;
                sort(d, d + 3, greater<int> ());
                break;
            }
        }
    } while(cont);
    for(int i = 0; i < 3; ++i) {
        if(c[i] != d[i]) {
            return c[i] < d[i];
        }
    }
    return equal_case;
}

int main() {
    int n = rd();
    for(int i = 0; i < n; ++i) {
        a[i].f = rd();
    }
    for(int i = 0; i < n; ++i) {
        a[i].s = rd();
        if(a[i].f == a[i].s) {
            ++a[i].f;
            a[i].s = 0;
        }
        if(a[i].f < a[i].s) {
            swap(a[i].f, a[i].s);
        }
        a[i].i = i;
    }
    sort(a, a + n);
    for(int l = 0, r = 0; l < n; l = r) {
        while(r < n && a[l] == a[r]) {
            ++r;
        }
        int low = l;
        for(int i = l - 1, val = 1, ff = 0; i >= 0; --i) {
            while(val <= n && !cmp(a[l], 1, a[i], val, 1)) {
                ++val;
            }
            if(n < val) {
                break;
            }
            ff = max(ff, i - (n - val));
            if(i < ff) {
                break;
            }
            --low;
        }
        int high = r;
        for(int i = r, val = n, ff = n; i < n; ++i) {
            while(val > 0 && !cmp(a[i], val, a[l], n, 0)) {
                --val;
            }
            if(val == 0) {
                break;
            }
            ff = min(ff, i + val - 1);
            if(ff < i) {
                break;
            }
            ++high;
        }
        for(int i = l; i < r; ++i) {
            res1[a[i].i] = low;
            res2[a[i].i] = high;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(i) {
            putchar('\n');
        }
        wr(res1[i] + 1);
        putchar(' ');
        wr(res2[i]);
    }
    return 0;
}

