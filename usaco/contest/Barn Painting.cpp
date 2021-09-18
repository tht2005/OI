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

const int nmax = 100010;
int n, m, col[nmax];
Mint dp[nmax][3];
vector<int> adj[nmax];

void dfs(int u, int p)
{
    if(~col[u]) dp[u][col[u]] = 1;
    else for(int i = 0; i < 3; ++i) dp[u][i] = 1;
    for(int v: adj[u]) if(v ^ p) {
        dfs(v, u);
        for(int c = 0; c < 3; ++c) if(dp[u][c].val) {
            if(col[v] == c) dp[u][c] = 0;
            Mint sum = 0;
            for(int c2 = 0; c2 < 3; ++c2) if(c ^ c2) sum += dp[v][c2];
            dp[u][c] *= sum;
        }
    }
}

int main()
{
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int _ = 0; _ + 1 < n; ++_) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(m --> 0) {
        int u; cin >> u >> col[u];
    }
    for(int i = 1; i <= n; ++i)
        --col[i];
    dfs(1, -1);
    Mint res = 0;
    for(int i = 0; i < 3; ++i)
        res += dp[1][i];
    cout << res;
    return 0;
}
