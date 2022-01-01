#include <bits/stdc++.h>

using namespace std;

int rd() {
    bool neg = 0; char c = getchar(); for(; c < '0' || c > '9'; c = getchar()) if(c == '-') neg = !neg;
    int n = 0; while('0' <= c && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = getchar();
    return neg ? -n : n;
}

typedef long long LL;

struct hash_table {
    static const int md = 400007, bs = 1000000007, MX = 2500011;
    int cnt, head[md], next[MX]; 
    LL val[MX];
    void init() {
        cnt = 0;
        memset(head, 0, sizeof(head));
    }
    void insert(int x, int y) {
        val[++cnt] = (LL)x * bs + y;
        int b = val[cnt] % md;
        next[cnt] = head[b];
        head[b] = cnt;
    }
    int query(int x, int y) {
        LL val_ = (LL)x * bs + y;
        int b = val_ % md;
        for(int i = head[b]; i; i = next[i])
            if(val_ == val[i])
                return i;
        return -1;
    }
} mp, mp2;
struct dsu {
    static const int MX = 2500011;
    int p[MX];
    void init(int n) {
        memset(p, -1, (n + 1) * sizeof *p);
    }
    int rt(int x) {
        return p[x] < 0 ? x : p[x] = rt(p[x]);
    }
    void join(int x, int y) {
        if((x = rt(x)) == (y = rt(y))) return;
        if(p[y] < p[x]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }
} d;

const int N = 100010;

struct dt {
    int x, y;
} a[N * 25];

int dx_[4] = { 0, 1, 0, -1 };
int dy_[4] = { 1, 0, -1, 0 };

int n, m, c, ok[N * 25], dfn[N * 25], low[N * 25], stk[30];
vector<int> aj[N * 25];

void dfs(int u, int p_, int& t, bool& f) {
    int cnt = 0;
    dfn[u] = low[u] = ++t;
    for(int v : aj[u]) if(v ^ p_) {
        if(dfn[v]) low[u] = min(low[u], dfn[v]);
        else {
            dfs(v, u, t, f);
            low[u] = min(low[u], low[v]);
            ++cnt;
            if(ok[u]) {
                if(p_ < 0 && cnt > 1) f = 1;
                if(~p_ && low[v] >= dfn[u]) f = 1;
            }
        }
    }
}
void pray_for_AC() {
    n = rd(), m = rd(), c = rd();
    mp.init();
    for(int i = 1; i <= c; ++i) {
        a[i].x = rd();
        a[i].y = rd();
        mp.insert(a[i].x, a[i].y);
    }
    if((LL)n * m - c < 2) {
        puts("-1");
    }
    else if((LL)n * m - c == 2) {
        auto [x, y, z, t] = make_tuple(-1, -1, -1, -1);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(mp.query(i, j) < 0) {
                    if(x < 0) x = i, y = j;
                    else z = i, t = j;
                }
            }
        }
        if(abs(x - z) + abs(y - t) == 1) puts("-1");
        else puts("0");
    }
    else {
        mp2.init();
        for(int i = 1; i <= c; ++i) {
            for(int dx = -2; dx <= 2; ++dx) {
                for(int dy = -2; dy <= 2; ++dy) {
                    if(!dx && !dy) continue;
                    int x = a[i].x + dx, y = a[i].y + dy;
                    if(x < 1 || x > n || y < 1 || y > m || ~mp.query(x, y)) continue;
                    int j = mp2.query(x, y);
                    if(j < 0) {
                        mp2.insert(x, y);
                        a[c + mp2.cnt] = { x, y };
                        j = mp2.cnt;
                    }
                    if(max(abs(dx), abs(dy)) == 1) ok[j] = 1;
                }
            }
        }
        d.init(mp2.cnt);
        for(int i = 1; i <= mp2.cnt; ++i) {
            for(int e = 0; e < 4; ++e) {
                int x = a[c + i].x + dx_[e], y = a[c + i].y + dy_[e];
                if(x < 1 || x > n || y < 1 || y > m || ~mp.query(x, y)) continue;
                int j = mp2.query(x, y);
                if(~j) {
                    aj[i].push_back(j);
                    d.join(i, j);
                }
            }
        }
        bool z = 0;
        for(int i = 1; i <= c && !z; ++i) {
            int top = 0;
            for(int dx = -2; dx <= 2; ++dx) {
                for(int dy = -2; dy <= 2; ++dy) {
                    if(!dx && !dy) continue;
                    int x = a[i].x + dx, y = a[i].y + dy;
                    if(x < 1 || x > n || y < 1 || y > m || ~mp.query(x, y)) continue;
                    stk[++top] = mp2.query(x, y);
                }
            }
            for(int j = 2; j <= top; ++j) {
                if(d.rt(stk[1]) != d.rt(stk[j])) {
                    z = 1;
                    break;
                }
            }
        }
        if(z) {
            puts("0");
        }
        else {
            bool f = n == 1 || m == 1;
            for(int i = 1; i <= mp2.cnt; ++i) {
                if(!dfn[i]) {
                    int t = 0;
                    dfs(i, -1, t, f);
                }
            }
            puts(f ? "1" : "2");
        }
        for(int i = 1; i <= mp2.cnt; ++i) {
            dfn[i] = ok[i] = 0;
            aj[i].clear();
        }
    }
}

int main() {
    int q = rd();
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
