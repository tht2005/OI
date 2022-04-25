#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m, cnt[N << 1], c[N][N];
bool f[N][N], g[N][N], r[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &c[i][j]);
        }
    }
    f[1][1] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1 + (i == 1); j <= m; ++j) {
            if(c[i][j]) continue;
            f[i][j] = f[i - 1][j] || f[i][j - 1];
        }
    }
    g[n][m] = 1;
    for(int i = n; i > 0; --i) {
        for(int j = m - (i == n); j > 0; --j) {
            if(c[i][j]) continue;
            g[i][j] = g[i + 1][j] || g[i][j + 1];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            r[i][j] = f[i][j] && g[i][j];
            if(r[i][j]) {
                ++cnt[i + j];
            }
        }
    }
    r[0][1] = r[n + 1][m] = 1;
    int _;
    scanf("%d", &_);
    while(_--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(r[x][y]) {
            if(cnt[x + y] > 1) {
                queue<pair<int, int>> q;
                r[x][y] = 0;
                --cnt[x + y];
                q.emplace(x, y);
                while(!q.empty()) {
                    auto [u, v] = q.front();
                    q.pop();
                    for(int e = 0; e < 4; ++e) {
                        int a = u + dx[e], b = v + dy[e];
                        if(a < 1 || a > n || b < 1 || b > m || !r[a][b]) continue;
                        if((!r[a - 1][b] && !r[a][b - 1]) || (!r[a + 1][b] && !r[a][b + 1])) {
                            r[a][b] = 0;
                            --cnt[a + b];
                            q.emplace(a, b);
                        }
                    }
                }
                putchar('1');
            }
            else {
                putchar('0');
            }
        }
        else {
            putchar('1');
        }
        putchar('\n');
    }
    return 0;
}
