/**
 *	Magician: KuriGohanKamehameha
 *	Spawned: 2021.10.16 21:22:44	
**/

#include <bits/stdc++.h>
using namespace std;

const int nmax = 355;

int n, k, a[nmax];
short memo[nmax][nmax][nmax];
string s;

int dp(int l, int r, int Anton, int Branka, int t)
{
	if(Anton == k) return 0;
	if(Branka == k) return 1;
	short& res = memo[l][r][Anton];
	if(~res) return res;
	if(t) {
		res = dp(l + 1, r, Anton, Branka + a[l], 0) & dp(l, r - 1, Anton, Branka + a[r], 0);
	}
	else {
		res = dp(l + 1, r, Anton + a[l], Branka, 1) | dp(l, r - 1, Anton + a[r], Branka, 1);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);	
	cin >> n >> k >> s;
	for(int i = 0; i < n; ++i)
		a[i] = s[i] == 'C' ? 1 : 0;
	memset(memo, -1, sizeof(memo));
	cout << (dp(0, n - 1, 0, 0, 0) ? "DA" : "NE");
	return 0;
}
