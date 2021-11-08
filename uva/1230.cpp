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
	int Q;
	scanf("%d", &Q);
	while(Q --> 0) {
		int x, y, n;
		scanf("%d %d %d", &x, &y, &n);
		int res = 1;
		for(; y > 0; y >>= 1, x = 1ll * x * x % n) {
			if(y & 1) {
				res = 1ll * res * x % n;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
