#include <bits/stdc++.h>

using namespace std;

const int md = (int)1e9 + 7;
void add(int& a, int b) {
    a += b;
    if(a >= md) a -= md;
    if(a < 0) a += md;
}

const int N = 500005;
int n, m, res, x[N], y[N], pref[26], suf[26], f[N][26];
stack<int> S, T;

int main() {
    scanf("%d %d", &n, &m);
    while(m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a < b) {
            x[a] = max(x[a], b);
        }
        else {
            y[b] = max(y[b], a);
        }
    }
    for(int i = 0; i < 26; ++i) {
        f[n][i] = 1;
    }
    for(int i = n - 1, j; i > 0; --i) {
        S.push(i + 1);
        for(int c = 0; c < 26; ++c) {
            add(pref[c], f[i + 1][c]);
        }
        while(!S.empty() && (j = S.top()) <= x[i]) {
            for(int c = 0; c < 26; ++c) {
                add(pref[c], -f[j][c]);
            }
            S.pop();
        }
        T.push(i + 1);
        for(int c = 0; c < 26; ++c) {
            add(suf[c], f[i + 1][c]);
        }
        while(!T.empty() && (j = T.top()) <= y[i]) {
            for(int c = 0; c < 26; ++c) {
                add(suf[c], -f[j][c]);
            }
            T.pop();
        }
        for(int c = 0, s = 0; c < 26; ++c) {
            f[i][c] = 1;
            add(f[i][c], s);
            add(s, pref[c]);
        }
        for(int c = 26, s = 0; c--; ) {
            add(f[i][c], s);
            add(s, suf[c]);
        }
    }
    for(int c = 0; c < 26; ++c) {
        add(res, f[1][c]);
    }
    printf("%d", res);
    return 0;
}
