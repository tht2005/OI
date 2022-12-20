#include <bits/stdc++.h>

using namespace std;

#define N 100005

int p[N];
long long res = 0;
map<int, int> cnt[N];
int rt(int x) {
    return (p[x] < 0) ? x : (p[x] = rt(p[x]));
}
void ae(int x, int y) {
    if((x = rt(x)) == (y = rt(y))) {
        return;
    }
    if(p[y] < p[x]) {
        swap(x, y);
    }
    p[x] += p[y];
    p[y] = x;
    for(const auto& [i, j] : cnt[y]) {
        res += (long long)cnt[x][i] * j;
        cnt[x][i] += j;
    }
    cnt[y].clear();
}

int A[N], B[N], Z[N], P[N];
long long R[N];
vector<pair<int, int>> aj[N];

void dfs(int v, int par, int S) {
    ++cnt[v][S];
    for(const auto& [w, u] : aj[v]) {
        if(u == par) {
            continue;
        }
        dfs(u, v, S ^ w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        cin >> A[i] >> B[i] >> Z[i];
        aj[A[i]].emplace_back(Z[i], B[i]);
        aj[B[i]].emplace_back(Z[i], A[i]);
    }
    for(int i = 1; i < n; ++i) {
        cin >> P[i];
    }
    dfs(1, 0, 0);
    memset(p, 0xff, sizeof(p));
    for(int i = n; i--; ) {
        R[i] = res;
        if(i) {
            ae(A[P[i]], B[P[i]]);
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << R[i] << '\n';
    }
    return 0;
}
