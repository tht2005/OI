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

typedef vector<int> lnum;
const int base = 1000 * 1000 * 1000;
void operator+= (lnum& a, const lnum& b) {
    int carry = 0;
    for(int i = 0; i < max(a.size(), b.size()) || carry; ++i) {
        if(i == a.size()) a.push_back(0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if(carry) a[i] -= base;
    }
}
void operator*= (lnum& a, int b) {
    int carry = 0;
    for(int i = 0; i < a.size() || carry; ++i) {
        if(i == a.size()) a.push_back(0);
        long long cur = carry + (long long)a[i] * b;
        a[i] = cur % base;
        carry = cur / base;
    }
}
void print(const lnum& a) {
    printf("%d", a.empty() ? 0 : a.back());
    for(int i = (int)a.size() - 2; i >= 0; --i)
        printf("%09d", a[i]);
}

typedef long long LL;

void pray_for_AC() {
    int n = rd(), k = rd();
    lnum f(1, 1), g(1, 0);
    for(int i = 0; i < n; ++i) {
        f.swap(g);
        g += f;
        g *= k - 1;
    }
    f += g;
    print(f);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q = 1;
    while(q--) {
        pray_for_AC();
    }
    return 0;
}
