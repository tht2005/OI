    #include <bits/stdc++.h>
     
    using namespace std;
     
    int rd() {
        char c = getchar(); while(c < '0' || c > '9') c = getchar();
        int n = 0; while('0' <= c && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = getchar();
        return n;
    }
    void wr(long long n) {
        static char o[20];
        int i = 0; do o[i++] = n % 10 + '0'; while(n /= 10);
        while(i--) putchar(o[i]);
    }
     
    typedef long long LL;
     
    const int N = 1000001;
    int n, mu[N];
    LL s, f[N];
    vector<int> d[N];
     
    int main() {
        mu[1] = 1;
        for(int i = 1; i < N; ++i)
            for(int j = i + i; j < N; j += i)
                mu[j] -= mu[i];
        for(int i = 1; i < N; ++i)
            for(int j = i; j < N; j += i)
                f[j] += i * mu[j / i];
        for(int i = 1; i < N; ++i)
            f[i] += f[i - 1];
        while(n = rd()) {
            s = 0;
            for(int i = 1, j; i <= n; i = j + 1) {
                j = n / (n / i);
                s += (LL)(n / i) * (n / i - 1) / 2 * (f[j] - f[i - 1]);
            }
            wr(s);
            putchar('\n');
        }
        return 0;
    }
    
