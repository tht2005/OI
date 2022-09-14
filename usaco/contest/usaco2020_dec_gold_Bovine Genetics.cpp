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

#define md 1000000007
void add(int& a, int b) {
    a += b;
    if(a >= md) {
        a -= md;
    }
}

#define N 100005

int a[N], f[N][4][4][4];

int main() {
    char c = getchar();
    while(c != 'A' && c != 'C' && c != 'G' && c != 'T' && c != '?') {
        c = getchar();
    }
    int n = 0;
    while(1) {
        if(c == 'A') {
            a[n++] = 0;
        }
        else if(c == 'C') {
            a[n++] = 1;
        }
        else if(c == 'G') {
            a[n++] = 2;
        }
        else if(c == 'T') {
            a[n++] = 3;
        }
        else if(c == '?') {
            a[n++] = -1;
        }
        else {
            break;
        }
        c = getchar();
    }
    memset(f, 0, sizeof(f));
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(a[0] == -1 || a[0] == j) {
                f[1][i][j][j] = 1;
            }
        }
    }
    for(int i = 1; i < n; ++i) {
        for(int x = 0; x < 4; ++x) {
            for(int y = 0 ; y < 4; ++y) {
                for(int z = 0; z < 4; ++z) {
                    int ft = f[i][x][y][z];
                    if(ft == 0) {
                        continue;
                    }
                    for(int j = 0; j < 4; ++j) {
                        if(a[i] != -1 && a[i] != j) {
                            continue;
                        }
                        if(z != j) {
                            add(f[i + 1][x][y][j], ft);
                        }
                        if(x == z) {
                            add(f[i + 1][y][j][j], ft);
                        }
                    }
                }
            }
        }
    }
    long long res = 0;
    for(int x = 0; x < 4; ++x) {
        for(int y = 0; y < 4; ++y) {
            res += f[n][x][y][x];
        }
    }
    printf("%lld", res % md);
    return 0;
}
