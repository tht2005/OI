/**
 *	Author: tht2005
 *	Gene: 2021.11.08 13:52:37	
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef __GNU_PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#endif

#define fs first
#define sc second
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()

using ll = long long;
using pi = std::pair<int, int>;
template<typename T> using vt = std::vector<T>;

int main()
{
#ifndef LOCAL
#endif
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		int res = 1;
		a %= c;
		for(; b > 0; b >>= 1, a = 1ll * a * a % c)
			if(b & 1) res = 1ll * res * a % c;
		printf("%d\n", res);
	}
	return 0;
}
