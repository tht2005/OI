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

LL M;
LL add(LL a, LL b) {
    a += b;
    if(a >= M) a -= M;
    if(a < 0) a += M;
    return a;
}
LL mul(LL a, LL b) {
    LL ret = 0;
    for(; b > 0; b >>= 1) {
        if(b & 1) ret = add(ret, a);
        a = add(a, a);
    }
    return ret;
}

struct matrix {
    static const int K = 2;
    LL mat[K][K];
    matrix() {}
    void identity() {
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < K; ++i)
            mat[i][i] = 1;
    }
    matrix& operator*= (const matrix& B) {
        LL w[K][K];
        for(int i = 0; i < K; ++i) {
            for(int j = 0; j < K; ++j) {
                w[i][j] = 0;
                for(int k = 0; k < K; ++k)
                    w[i][j] = add(w[i][j], mul(mat[i][k], B.mat[k][j]));
            }
        }
        memcpy(mat, w, sizeof(mat));
        return *this;
    }
    matrix& binpow(LL N) {
        matrix A(*this);
        identity();
        for(; N > 0; N >>= 1) {
            if(N & 1) *this *= A;
            A *= A;
        }
        return *this;
    }
};

void pray_for_AC() {
    LL n, k;
    scanf("%lld %lld %lld", &n, &k, &M);
    matrix A, B;
    A.mat[0][0] = 1;
    A.mat[0][1] = 0;
    B.mat[0][0] = 0;
    B.mat[1][0] = 1;
    B.mat[0][1] = B.mat[1][1] = add(k % M, -1);
    B.binpow(n);
    A *= B;
    printf("%lld", add(A.mat[0][0], A.mat[0][1]));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
