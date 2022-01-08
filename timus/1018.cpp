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

const int N = 101;
vector<int> dp[N];
vector<pair<int, int>> aj[N];

void comb(vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() - 1, -1);
    c[0] = 0;
    for(int i = 1; i < (int)a.size(); ++i)
        for(int j = 0; j < (int)b.size(); ++j)
            c[i + j] = max(c[i + j], a[i] + b[j]);
    a.swap(c);
}
void dfs(int v, int p, int w) {
    dp[v].resize(2);
    dp[v][0] = 0;
    dp[v][1] = w;
    for(auto [w_, u] : aj[v]) {
        if(u == p) continue;
        dfs(u, v, w_);
        comb(dp[v], dp[u]);
    }
}
int main() {
    int n = rd(), k = rd() + 1;
    for(int _ = 1; _ < n; ++_) {
        int u = rd() - 1, v = rd() - 1, w = rd();
        aj[u].emplace_back(w, v);
        aj[v].emplace_back(w, u);
    }
    dfs(0, -1, 0);
    wr(dp[0][k]);
    return 0;
}
