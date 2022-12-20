#include <bits/stdc++.h>

using namespace std;

#define N 16384

int st[N << 1];
void update(int x, int d) {
    for(st[x += N] = d; x > 1; x >>= 1) {
        st[x >> 1] = max(st[x], st[x ^ 1]);
    }
}
int query(int l, int r) {
    int res = 0;
    for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if(l & 1) {
            res = max(res, st[l++]);
        }
        if(r & 1) {
            res = max(res, st[--r]);
        }
    }
    return res;
}

int par[N], big[N], d[N], cnt, head[N], pos[N];
vector<pair<int, int>> aj[N];

int pre_dfs(int v, int p) {
    par[v] = p;
    big[v] = 0;
    int sz = 1, mx = 0;
    for(const auto& [w, u] : aj[v]) {
        if(u == p) {
            continue;
        }
        d[u] = d[v] + 1;
        int tmp = pre_dfs(u, v);
        sz += tmp;
        if(mx < tmp) {
            big[v] = u;
            mx = tmp;
        }
    }
    return sz;
}
void dfs(int v, int p, int h) {
    head[v] = h;
    pos[v] = ++cnt;
    if(big[v]) {
        dfs(big[v], v, h);
    }
    for(const auto& [w, u] : aj[v]) {
        if(u == p || u == big[v]) {
            continue;
        }
        dfs(u, v, u);
    }
}

int uu[N], vv[N], ww[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1, u, v, w; i < n; ++i) {
            cin >> u >> v >> w;
            aj[u].emplace_back(w, v);
            aj[v].emplace_back(w, u);
            uu[i] = u;
            vv[i] = v;
            ww[i] = w;
        }
        pre_dfs(1, 0);
        cnt = 0;
        dfs(1, 0, 1);
        for(int i = 1; i < n; ++i) {
            if(par[uu[i]] == vv[i]) {
                swap(uu[i], vv[i]);
            }
            update(pos[vv[i]], ww[i]);
        }
        string o;
        while(cin >> o) {
            if(o[0] == 'D') {
                break;
            }
            int i, j;
            cin >> i >> j;
            if(o[0] == 'C') {
                update(pos[vv[i]], j);
            }
            else {
                int res = 0;
                for(; head[i] != head[j]; j = par[head[j]]) {
                    if(d[head[i]] > d[head[j]]) {
                        swap(i, j);
                    }
                    res = max(res, query(pos[head[j]], pos[j] + 1));
                }
                if(d[i] > d[j]) {
                    swap(i, j);
                }
                if(pos[i] < pos[j]) {
                	res = max(res, query(pos[i] + 1, pos[j] + 1));	
                }
                cout << res << '\n';
            }
        }
        for(int i = 1; i <= n; ++i) {
            aj[i].clear();
        }
    }
    return 0;
}
