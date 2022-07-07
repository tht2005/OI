#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define C 21

int f[1 << C], cnt[C][1 << C];
char s[N], v[N];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; ++i) {
        v[i] = s[i];
    }
    sort(v, v + n);
    int m = unique(v, v + n) - v;
    for(int i = 0; i < n; ++i) {
        s[i] = lower_bound(v, v + m, s[i]) - v + 'a';
    }
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i < n; ++i) {
        ++cnt[s[i - 1] - 'a'][1 << (s[i] - 'a')];
    }
    for(int i = 0; i < m; ++i) {
        for(int t = 1, w; t < 1 << m; ++t) {
            w = t & (t - 1);
            if(w) {
                cnt[i][t] = cnt[i][w] + cnt[i][t ^ w];
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 1;
    for(int t = 1; t < 1 << m; ++t) {
        for(int i = 0; i < m; ++i) {
            if(t >> i & 1) {
                f[t] = min(f[t], f[t ^ (1 << i)] + cnt[i][t]);
            }
        }
    }
    printf("%d", f[(1 << m) - 1]);
    return 0;
}
