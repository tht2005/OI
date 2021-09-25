#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll pw[18], memo[20][2];

ll cnt(const string& s, int i, int tight)
{
	if(tight) return pw[s.size() - i];
	if(i == s.size()) return 1;
	ll res = 0;
	for(int c = 0; c + 48 < s[i]; ++c)
		res += cnt(s, i + 1, 1);
	res += cnt(s, i + 1, 0);
	return res;
}

ll dp(const string& s, int i, int tight)
{
	ll& res = memo[i][tight];
	if(~res) return res;
	if(i == s.size()) return res = 0;
	res = 0;
	if(tight) {
		for(int c = 0; c < 10; ++c) {
			res += dp(s, i + 1, 1) + c * cnt(s, i + 1, 1);
		}
	}
	else {
		for(int c = 0; c + 48 < s[i]; ++c) {
			res += dp(s, i + 1, 1) + c * cnt(s, i + 1, 1);
		}
		res += dp(s, i + 1, 0) + (s[i] - 48) * cnt(s, i + 1, 0);
	}
	return res;
}

ll calc(ll i)
{
	string s = to_string(i);
	memset(memo, -1, sizeof(memo));
	return dp(s, 0, 0);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	pw[0] = 1;
	for(int i = 1; i < 18; ++i) pw[i] = pw[i - 1] * 10;
	int T; cin >> T;
	while(T --> 0) {
		ll l, r; cin >> l >> r;
		cout << calc(r) - (l ? calc(l - 1) : 0) << '\n';
	}
	return 0;
}
