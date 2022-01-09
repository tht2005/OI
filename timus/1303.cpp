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

bool ckmin(int& a, int b) {
    return a > b ? a = b, 1 : 0;
}

const int INF = 1000000000;

int main() {
    int M = rd();
    vector<int> L, R, x(M + 1, INF), y(M + 1);
    for(int i = 0, l, r; scanf("%d %d", &l, &r), l || r; ++i) {
        L.push_back(l);
        R.push_back(r);
        if(l > M || r < 0) continue;
        if(ckmin(x[min(r, M)], max(l, 0)))
            y[min(r, M)] = i;
    }
    vector<int> dp(M + 1), trc(M + 1);
    dp[0] = 0;
    for(int i = 1; i <= M; ++i) {
        dp[i] = INF;
        if(!x[i]) {
            dp[i] = 1;
            trc[i] = 0;
        }
        for(int j = x[i]; j < i; ++j)
            if(ckmin(dp[i], dp[j] + 1))
                trc[i] = j;
    }
    if(dp[M] < INF) {
        wr(dp[M]);
        vector<pair<int, int>> p;
        while(M) {
            p.emplace_back(L[y[M]], R[y[M]]);
            M = trc[M];
        }
        sort(p.begin(), p.end());
        for(const auto& _ : p) {
            putchar('\n');
            wr(_.first);
            putchar(' ');
            wr(_.second);
        }
    }
    else {
        puts("No solution");
    }
    return 0;
}
