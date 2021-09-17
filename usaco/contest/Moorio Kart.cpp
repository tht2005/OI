#include <bits/stdc++.h>
using namespace std;

template<typename T, T md>
struct mint
{
    T val;

    mint(T init = 0) : val(init) {}

    T operator= (T rhs) { return val = rhs; }

    mint operator+ (mint rhs) { return mint(add(val, rhs.val)); }
    mint operator- (mint rhs) { return mint(sub(val, rhs.val)); }
    mint operator* (mint rhs) { return mint(mul(val, rhs.val)); }

    mint& operator+= (mint rhs) { val = add(val, rhs.val); return *this; }
    mint& operator-= (mint rhs) { val = sub(val, rhs.val); return *this; }
    mint& operator*= (mint rhs) { val = mul(val, rhs.val); return *this; }

    friend istream& operator>> (istream& is, mint& rhs) { return is >> rhs.val; }
    friend ostream& operator<< (ostream& os, mint& rhs) { return os << rhs.val; }

    inline T add(T a, T b)
    {
        if((a += b) >= md) a -= md;
        return a;
    }

    inline T sub(T a, T b)
    {
        if((a -= b) < 0) a += md;
        return a;
    }

    inline T mul(T a, T b)
    {
        return 1ll * a * b % md;
    }
};

using Mint = mint<int, (int)1e9 + 7>;
using ii = pair<int, int>;

struct dt
{
    Mint f, s;

    dt operator+ (dt rhs)
    {
        return {f + rhs.f, s + rhs.s};
    }

    dt& operator+= (dt rhs)
    {
        return *this = *this + rhs;
    }

    friend dt comb(dt l, dt r)
    {
        return {(l.f * r.s) + (l.s * r.f), l.s * r.s};
    }
};

int n, m, k, x, y, vst[1550];
dt dp[2550], aux[2550];
vector<int> comp, dist;
vector<ii> adj[1550];

void dfs(int u)
{
    if(vst[u]) return;
    vst[u] = 1;
    comp.push_back(u);
    for(auto [w, v]: adj[u])
        dfs(v);
}

void dfs2(int u, int p, int r, int d)
{
    for(auto [w, v]: adj[u]) if(v ^ p) {
        if(r < v)
            dist.push_back(d + w);
        dfs2(v, u, r, d + w);
    }
}

int main()
{
    freopen("mooriokart.in", "r", stdin);
    freopen("mooriokart.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> x >> y;
    k = n - m;
    for(int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dp[min(k * x, y)] = {k * x, 1};
    for(int i = 1; i <= n; ++i) if(!vst[i]) {
        comp.clear();
        dfs(i);
        dist.clear();
        for(int v: comp)
            dfs2(v, -1, v, 0);
        map<int, dt> mp;
        for(int j: dist) {
            mp[min(j, y)] += {j, 1};
        }
        for(int j = 0; j <= y; ++j) {
            aux[j] = {0, 0};
        }
        for(auto k: mp) {
            for(int j = 0; j <= y; ++j) {
                aux[min(y, k.first + j)] += comb(dp[j], k.second);
            }
        }
        for(int j = 0; j <= y; ++j)
            dp[j] = aux[j];
    }
    for(int i = 0; i < k - 1; ++i)
        dp[y].f *= 2;
    for(int i = 1; i < k; ++i)
        dp[y].f *= i;
    cout << dp[y].f;
    return 0;
}
