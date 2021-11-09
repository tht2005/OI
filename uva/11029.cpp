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

const int md = 1000;

int binpow(int a, int n)
{
	int res = 1;
	for(a %= md; n > 0; n >>= 1, a = a * a % md)
		if(n & 1) res = res * a % md;
	return res;
}

int main()
{
#ifndef LOCAL
#endif
	int Q;
	scanf("%d", &Q);
	while(Q --> 0) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d...%03d\n", (int)(pow(10, fmod(k * log10(n), 1)) * 100), binpow(n, k));
	}
	return 0;
}
