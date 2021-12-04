#include <cstdio>
#include <cstdlib>
#include <cstring>

void rd(int& n) {
    char c = getchar(); while(c < '0' || c > '9') c = getchar();
    n = 0; while('0' <= c && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = getchar();
}
void wr(int n) {
    static char os[20];
    int i = 0; do os[i++] = n % 10 + '0'; while(n /= 10);
    while(i--) putchar(os[i]);
}

#define N       1024010

char s[55];
int a[N], st[N << 2], lz[N << 2];

#define lc      (x << 1)
#define rc      (lc | 1)
#define m       ((l + r) >> 1)

void flip(int& x) {
    if(x == 1) x = 2;
    else if(x == 2) x = 1;
    else if(x == 3) x = 0;
    else x = 3;
}
void push(int x, int l, int r) {
    if(lz[x]) {
        if(l ^ r) {
            if(lz[x] == 3) {
                flip(lz[lc]), flip(lz[rc]);
            }
            else {
                lz[lc] = lz[rc] = lz[x];
            }
        }
        if(lz[x] == 1) st[x] = r - l + 1;
        else if(lz[x] == 2) st[x] = 0;
        else st[x] = r - l + 1 - st[x];
        lz[x] = 0;
    }
}
void pull(int x) {
    st[x] = st[lc] + st[rc];
}
void build(int x, int l, int r) {
    lz[x] = 0;
    if(l ^ r) {
        build(lc, l, m), build(rc, m + 1, r), pull(x);
    }
    else {
        st[x] = a[l];
    }
}
void modify(int x, int l, int r, int ql, int qr, int op) {
    push(x, l, r); if(r < ql || qr < l) return;
    if(ql <= l && r <= qr) {
        lz[x] = op, push(x, l, r);
    }
    else {
        modify(lc, l, m, ql, qr, op), modify(rc, m + 1, r, ql, qr, op), pull(x);
    }
}
int query(int x, int l, int r, int ql, int qr) {
    push(x, l, r); if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return st[x];
    return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

#undef lc
#undef rc
#undef m

int main() {
    int T; rd(T);
    for(int iT = 1; iT <= T; ++iT) {
        int n = 0;
        int m; rd(m);
        while(m--) {
            int tt; rd(tt);
            scanf("%s", s);
            int len = strlen(s);
            while(tt--) {
                for(int i = 0; i < len; ++i) {
                    a[n++] = s[i] - '0';
                }
            }
        }
        build(1, 0, n - 1);
        printf("Case %d:\n", iT);
        int Q, i = 0;
        rd(Q);
        for(int iQ = 1; iQ <= Q; ++iQ) {
            int l, r; char c;
            scanf(" %c", &c), rd(l), rd(r);
            if(c == 'F') {
                modify(1, 0, n - 1, l, r, 1);
            }
            else if(c == 'E') {
                modify(1, 0, n - 1, l, r, 2);
            }
            else if(c == 'I') {
                modify(1, 0, n - 1, l, r, 3);
            }
            else {
                printf("Q%d: %d\n", ++i, query(1, 0, n - 1, l, r));
            }
        }
    }
    return 0;
}
