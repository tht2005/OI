#include <bits/stdc++.h>
using namespace std;

class EllysKeys
{
public:
	int getMax(vector<string> keys)
	{
		int n = keys[0].size();
		vector<int> dp(1 << n, 0);
		for(const string& s : keys) {
			int mask = 0;
			for(int i = 0; i < n; ++i) {
				if(s[i] == '^') {
					mask |= 1 << i;
				}
			}
			for(int i = (1 << n) - 1; i >= 0; --i) {
				if(i & mask) continue;
				dp[i | mask] = max(dp[i | mask], dp[i] + 1);
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};
