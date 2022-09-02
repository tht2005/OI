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

#define N 1003

vector<int> aj[N];
int w[N], f[N][N];

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n = rd(), m = rd(), C = rd();
    for(int i = 0; i < n; ++i) {
        w[i] = rd();
    }
    while(m--) {
        int u = rd() - 1, v = rd() - 1;
        aj[u].push_back(v);
    }
    memset(f, 0xff, sizeof(f));
    f[0][0] = 0;
    for(int t = 0; t < 1000; ++t) {
        for(int i = 0; i < n; ++i) {
            if(f[t][i] == -1) {
                continue;
            }
            for(int j : aj[i]) {
                f[t + 1][j] = max(f[t + 1][j], f[t][i] + w[j]);
            }
        }
    }
    int res = 0;
    for(int t = 1; t <= 1000; ++t) {
        res = max(res, f[t][0] - C * t * t);
    }
    wr(res);
    return 0;
}

