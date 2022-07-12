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

#define md 1000000007
int add(int a, int b) {
    a += b;
    if(a >= md) {
        a -= md;
    }
    if(a < 0) {
        a += md;
    }
    return a;
}

#define N 10004
int f[N][2], c[N];
vector<int> aj[N];

void dfs(int v, int p, int t) {
    f[v][0] = f[v][1] = 0;
    if(c[v] == -1) {
        f[v][0] = 1;
    }
    else {
        f[v][1] = t >> c[v] & 1;
    }
    for(int u : aj[v]) {
        if(u == p) {
            continue;
        }
        dfs(u, v, t);
        long long aux0 = f[v][0] + (long long)f[v][0] * f[u][0];
        long long aux1 = f[v][1] + (long long)f[v][0] * f[u][1] + (long long)f[v][1] * f[u][0] + (long long)f[v][1] * f[u][1];
        f[v][0] = aux0 % md;
        f[v][1] = aux1 % md;
    }
}

int main() {
    int n = rd(), k = rd();
    for(int i = 0; i < n; ++i) {
        c[i] = rd() - 1;
        if(c[i] >= k) {
            c[i] = -1;
        }
    }
    for(int i = 1, u, v; i < n; ++i) {
        u = rd() - 1;
        v = rd() - 1;
        aj[u].push_back(v);
        aj[v].push_back(u);
    }
    int res = 0;
    for(int t = 1, s; t < 1 << k; ++t) {
        dfs(0, -1, t);
        s = 0;
        for(int i = 0; i < n; ++i) {
            s = add(s, f[i][1]);
        }
        res = add(res, __builtin_parity(((1 << k) - 1) ^ t) ? -s : s);
    }
    wr(res);
    return 0;
}
