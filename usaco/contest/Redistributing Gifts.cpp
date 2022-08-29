#include <bits/stdc++.h>

using namespace std;

#define LL long long

#define N 18

int a[N];
LL res[1 << N], f[1 << N][N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0, j, k; i < n; ++i) {
        a[i] = 0;
        for(j = 0; j < n; ++j) {
            scanf("%d", &k);
            --k;
            a[i] |= 1 << k;
            if(i == k) {
                break;
            }
        }
        for(++j; j < n; ++j) {
            scanf("%d", &k);
        }
    }
    res[0] = 1;
    for(int i = 0; i < n; ++i) {
        f[1 << i][i] = 1;
    }
    for(int i = 0; i < n; ++i) {
        for(int t = 1 << i; t < 1 << (i + 1); ++t) {
            for(int j = 0; j <= i; ++j) {
                if(!(t >> j & 1)) {
                    continue;
                }
                LL ft = f[t][j];
                for(int k = 0; k < i; ++k) {
                    if((t >> k & 1) || !(a[j] >> k & 1)) {
                        continue;
                    }
                    f[t | (1 << k)][k] += ft;
                }
                if(a[j] >> i & 1) {
                    res[t] += ft;
                }
            }
            for(int j = i + 1; j < n; ++j) {
                f[t | (1 << j)][j] += res[t];
            }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        char c = getchar();
        while(c != 'H' && c != 'G') {
            c = getchar();
        }
        int t = 0;
        for(int i = 0; i < n; ++i) {
            if(c == 'H') {
                t |= 1 << i;
            }
            c = getchar();
        }
        printf("%lld\n", res[t] * res[((1 << n) - 1) ^ t]);
    }
    return 0;
}
