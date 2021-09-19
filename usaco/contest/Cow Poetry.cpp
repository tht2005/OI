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

Mint power(Mint a, int n)
{
    Mint res = 1;
    for(; n > 0; n >>= 1, a *= a)
        if(n & 1) res *= a;
    return res;
}

int main()
{
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    for(auto& [s, c]: a) {
        cin >> s >> c;
        --c;
    }
    vector<Mint> w(n), dp(k + 1);
    dp[0] = 1;
    for(int j = 0; j <= k; ++j) {
        for(auto [s, c]: a) {
            if(j + s < k) {
                dp[j + s] += dp[j];
            }
            else if(j + s == k) {
                w[c] += dp[j];
            }
        }
    }
    vector<int> cnt(26, 0);
    while(m --> 0) {
        char c; cin >> c;
        ++cnt[c - 'A'];
    }
    Mint res = 1;
    for(int c = 0; c < 26; ++c) if(cnt[c]) {
        Mint sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += power(w[i], cnt[c]);
        }
        res *= sum;
    }
    cout << res;
    return 0;
}
