/**
 *	Magician: tht2005
 *	Spawned: 2021.10.18 20:18:41	
**/

#include <bits/stdc++.h>
using namespace std;

const int nmax = 55;

int n;
char a[nmax][nmax];
string memo[nmax][nmax];

string dp(int s, int t)
{
	if(s == t) return "";
	string& res = memo[s][t];
	if(res != "-") return res;
	res = a[s][t];
	string str;
	for(int i = s + 1; i < t; ++i) {
		if(a[s][i] != '*') {
			for(int j = i; j < t; ++j) {
				if(a[s][i] == a[j][t]) {
					str = a[s][i] + dp(i, j) + a[j][t];
					if(res.size() < str.size() || (res.size() == str.size() && res > str))
						res = str;
				}
			}
		}
	}
	return memo[s][t];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int Q;
	cin >> Q;
	while(Q --> 0) {
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cin >> a[i][j];
				memo[i][j] = "-";
			}
		}
		string res = dp(0, n - 1);
		if(res == "*") {
			cout << "NO PALINDROMIC PATH" << '\n';
		}
		else {
			cout << res << '\n';
		}
	}
	return 0;
}
