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

typedef long long LL;

bool ckmin(LL& a, LL b) {
    return a > b ? a = b, 1 : 0;
}

const LL INF = 1ll << 60;
int a[100][500], trc[100][500];
LL d[100][500];

void pray_for_AC() {
    int n = rd(), m = rd();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            a[i][j] = rd();
    priority_queue<tuple<LL, int, int>> q;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            d[i][j] = INF;
    for(int i = 0; i < m; ++i) {
        d[n - 1][i] = a[n - 1][i];
        q.emplace(-d[n - 1][i], n - 1, i);
    }
    int c = -1;
    while(!q.empty()) {
        auto [d_, x, y] = q.top();
        q.pop();
        if(d[x][y] != -d_) continue;
        if(x == 0) {
            c = y;
            break;
        }
        if(y && ckmin(d[x][y - 1], a[x][y - 1] - d_)) {
            q.emplace(d_ - a[x][y - 1], x, y - 1);
            trc[x][y - 1] = 1;
        }
        if(y + 1 < m && ckmin(d[x][y + 1], a[x][y + 1] - d_)) {
            q.emplace(d_ - a[x][y + 1], x, y + 1);
            trc[x][y + 1] = -1;
        }
        if(ckmin(d[x - 1][y], a[x - 1][y] - d_)) {
            q.emplace(d_ - a[x - 1][y], x - 1, y);
            trc[x - 1][y] = 0;
        }
    }
    int r = 0;
    while(1) {
        wr(c + 1);
        if(r + 1 == n) break;
        int i = trc[r][c];
        if(!i) ++r;
        c += i;
        putchar(' ');
    }
}

int main() {
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
