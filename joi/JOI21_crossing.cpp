#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int n;
char s[9][N], t[N];

void add(char* r, char* a, char* b) {
    for(int i = 0; i < n; ++i) {
        if(a[i] == b[i]) {
            r[i] = a[i];
        }
        else {
            r[i] = 'J' + 'O' + 'I' - a[i] - b[i];
        }
    }
}

const int N_ = 262144;
char st[9][N_ << 1], lz[N_ << 1];
bool res[9][N_ << 1];
void build(int x, int l, int r) {
    lz[x] = 0;
    if(l == r) {
        for(int i = 0; i < 9; ++i) {
            st[i][x] = s[i][l];
            res[i][x] = (s[i][l] == t[l]);
        }
    }
    else {
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        for(int i = 0; i < 9; ++i) {
            st[i][x] = (st[i][x << 1] == st[i][x << 1 | 1]) ? st[i][x << 1] : 0;
            res[i][x] = res[i][x << 1] && res[i][x << 1 | 1];
        }
    }
}
void push(int x, int l, int r) {
    if(lz[x]) {
        for(int i = 0; i < 9; ++i) {
            res[i][x] = (st[i][x] == lz[x]);
        }
        if(l != r) {
            lz[x << 1] = lz[x << 1 | 1] = lz[x];
        }
        lz[x] = 0;
    }
}
void update(int x, int l, int r, int ql, int qr, char d) {
    push(x, l, r); if(r < ql || qr < l) return;
    if(ql <= l && r <= qr) {
        lz[x] = d;
        push(x, l, r);
    }
    else {
        int m = (l + r) >> 1;
        update(x << 1, l, m, ql, qr, d);
        update(x << 1 | 1, m + 1, r, ql, qr, d);
        for(int i = 0; i < 9; ++i) {
            res[i][x] = res[i][x << 1] && res[i][x << 1 | 1];
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 3; ++i) {
        scanf("%s", s[i]);
    }
    add(s[3], s[0], s[1]);
    add(s[4], s[0], s[2]);
    add(s[5], s[1], s[2]);
    add(s[6], s[3], s[2]);
    add(s[7], s[4], s[1]);
    add(s[8], s[5], s[0]);
    int q;
    scanf("%d %s", &q, t);
    build(1, 0, n - 1);
    bool ok = 0;
    for(int i = 0; i < 9; ++i) {
        if(res[i][1]) {
            ok = 1;
            break;
        }
    }
    puts(ok ? "Yes" : "No");
    while(q--) {
        int l, r;
        char c;
        scanf("%d %d %c", &l, &r, &c);
        update(1, 0, n - 1, l - 1, r - 1, c);
        ok = 0;
        for(int i = 0; i < 9; ++i) {
            if(res[i][1]) {
                ok = 1;
                break;
            }
        }
        puts(ok ? "Yes" : "No");
    }
    return 0;
}
