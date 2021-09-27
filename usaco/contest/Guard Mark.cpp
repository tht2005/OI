#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int main()
{
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	int n, H;
	scanf("%d %d", &n, &H);
	vector<int> h(n), w(n), s(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d %d", &h[i], &w[i], &s[i]);
	}
	int res = -1;
	vector<int> sw(1 << n, 0), dp(1 << n, -inf);
	dp[0] = inf;
	for(int mask = 1; mask < 1 << n; ++mask) {
		int last = mask & -mask, sum = 0;
		sw[mask] = sw[mask & ~last] + w[__builtin_ctz(mask)];
		for(int i = 0; i < n; ++i) if(mask >> i & 1) {
			sum += h[i];
			dp[mask] = max(dp[mask], min(dp[mask & ~(1 << i)], s[i] - sw[mask & ~(1 << i)]));
		}
		if(sum >= H) res = max(res, dp[mask]);
	}
	if(~res) {
		printf("%d", res);
	}
	else {
		printf("Mark is too tall");
	}
	return 0;
}
