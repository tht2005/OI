#include <bits/stdc++.h>
using namespace std;

const int md = 1000'000'007;
void add(int& a, int b) {
	a += b;
	if(a >= md) a -= md;
	if(a < 0) a += md;
}
#define mul(a, b) ((long long)(a) * (b) % md)

int binpow(int a, int n) {
	int res = 1;
	for(; n > 0; n >>= 1) {
		if(n & 1)
			res = mul(res, a);
		a = mul(a, a);
	}
	return res;
}
#define inverse(a) binpow(a, md - 2)

const int K = 55;

int nCr[K][K], inv[K];
int dp[K];

void init() {
	for(int i = 0; i < K; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for(int j = 1, k = i >> 1; j <= k; ++j) {
			nCr[i][j] = nCr[i - 1][j - 1];
			add(nCr[i][j], nCr[i - 1][j]);
			nCr[i][i - j] = nCr[i][j];
		}
	}
	for(int i = 0; i < K; ++i)
		inv[i] = inverse(i);
}

int c11cal(int n, int k) {
	dp[0] = n % md;
	for(int i = 1, val = (n + 1) % md; i <= k; ++i) {
		val = mul(val, n + 1);
		dp[i] = val;
		add(dp[i], -1);
		for(int j = 0; j < i; ++j)
			add(dp[i], -mul(nCr[i + 1][j], dp[j]));
		dp[i] = mul(dp[i], inv[i + 1]);
	}
	return dp[k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int n, k;
	while(cin >> n >> k) {
		cout << c11cal(n, k) << '\n';
	}
	return 0;
}
