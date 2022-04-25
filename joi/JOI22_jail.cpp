#include <bits/stdc++.h>

using namespace std;

const int N = 120005;
const int L = 17;

int cnt, s[N], t[N], tin[N], tout[N], p[N][L], e[N][L], f[N][L], c[N * L * 2];
vector<int> aj[N];
vector<int> ej[N * L * 2];

#define ae(u, v) {\
    ej[(u)].push_back((v));\
}

void dfs(int v, int p_) {
    tin[v] = ++(*tin);
    p[v][0] = p_;
    for(int i = 0, u; i + 1 < L && (u = p[v][i]) && p[u][i]; ++i) {
        p[v][i + 1] = p[u][i];
        if(e[v][i] && e[u][i]) {
            e[v][i + 1] = ++cnt;
            ae(e[v][i], cnt);
            ae(e[u][i], cnt);
        }
        else {
            e[v][i + 1] = e[v][i] | e[u][i];
        }
        if(f[v][i] && f[u][i]) {
            f[v][i + 1] = ++cnt;
            ae(cnt, f[v][i]);
            ae(cnt, f[u][i]);
        }
        else {
            f[v][i + 1] = f[v][i] | f[u][i];
        }
    }
    for(int u : aj[v]) {
        if(u == p_) continue;
        dfs(u, v);
    }
    tout[v] = (*tin);
}

int anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}
int lca(int v, int u) {
    if(anc(v, u)) return v;
    if(anc(u, v)) return u;
    for(int i = L; i--; ) {
        if(p[v][i] && !anc(p[v][i], u)) {
            v = p[v][i];
        }
    }
    return p[v][0];
}

bool dfs(int v) {
    c[v] = 1;
    for(int u : ej[v]) {
        if(c[u] == 1 || (c[u] == 0 && dfs(u))) {
            return 1;
        }
    }
    c[v] = -1;
    return 0;
}

int main() {
    int _;
    scanf("%d", &_);
    while(_--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            aj[u].push_back(v);
            aj[v].push_back(u);
        }
        int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d %d", s + i, t + i);
            e[s[i]][0] = i;
            f[t[i]][0] = i;
        }
        cnt = m;
        dfs(1, 0);
        for(int i = 1; i <= m; ++i) {
            int x = lca(s[i], t[i]);
            int v;
            if(s[i] != x) {
                v = *p[s[i]];
                for(int j = L; j--; ) {
                    if(p[v][j] && !anc(p[v][j], x)) {
                        if(e[v][j]) {
                            ae(e[v][j], i);
                        }
                        if(f[v][j]) {
                            ae(i, f[v][j]);
                        }
                        v = p[v][j];
                    }
                }
                if(v && v != x) {
                    if((*e[v]) && (*e[v]) != i) {
                        ae(*e[v], i);
                    }
                    if((*f[v]) && (*f[v]) != i) {
                        ae(i, *f[v]);
                    }
                }
            }
            if(t[i] != x) {
                v = *p[t[i]];
                for(int j = L; j--; ) {
                    if(p[v][j] && !anc(p[v][j], x)) {
                        if(e[v][j]) {
                            ae(e[v][j], i);
                        }
                        if(f[v][j]) {
                            ae(i, f[v][j]);
                        }
                        v = p[v][j];
                    }
                }
                if(v && v != x) {
                    if((*e[v]) && (*e[v]) != i) {
                        ae(*e[v], i);
                    }
                    if((*f[v]) && (*f[v]) != i) {
                        ae(i, *f[v]);
                    }
                }
            }
            for(int u : { s[i], t[i], x }) {
                if((*e[u]) && (*e[u]) != i) {
                    ae(*e[u], i);
                }
                if((*f[u]) && (*f[u]) != i) {
                    ae(i, *f[u]);
                }
            }
        }
        bool cyc = 0;
        for(int i = 1; i <= cnt; ++i) {
            if(c[i] == 0 && dfs(i)) {
                cyc = 1;
                break;
            }
        }
        puts(cyc ? "No" : "Yes");
        for(int i = 1; i <= n; ++i) {
            memset(p[i], 0, sizeof(p[i]));
            memset(e[i], 0, sizeof(e[i]));
            memset(f[i], 0, sizeof(f[i]));
            aj[i].clear();
        }
        for(int i = 1; i <= cnt; ++i) {
            c[i] = 0;
            ej[i].clear();
        }
    }
    return 0;
}
