/**
 *	Author: tht2005
 *	Gene: 2021.11.03 20:48:36	
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

struct edge
{
	int i, j, k;

	bool operator< (const edge& rhs) const {
		return k < rhs.k || (k == rhs.k && make_pair(i, j) < make_pair(rhs.i, rhs.j));
	}
};

const int N = 10010;
const int M = 100010;
const int inf = numeric_limits<int>::max();

int cc, p[N];
ll sum;
edge lst[M], ext[N];

int rt(int x)
{
	return p[x] < 0 ? x : p[x] = rt(p[x]);
}

int jn(int x, int y)
{
	if((x = rt(x)) == (y = rt(y)))
		return 0;
	if(p[y] < p[x])
		swap(x, y);
	p[x] += p[y];
	p[y] = x;
	return 1;
}

int main()
{
#ifndef LOCAL
#endif
	std::cin.tie(NULL)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i_ = 0; i_ < m; ++i_) {
		int i, j, k;
		cin >> i >> j >> k;
		if(--i > --j)
			swap(i, j);
		lst[i_] = {i, j, k};
	}
	cc = n;
	for(int i = 0; i < n; ++i)
		p[i] = -1;
	sum = 0;
	lst[m] = {inf, inf, inf};
	while(cc > 1) {
		for(int i = 0; i < n; ++i)
			ext[i] = lst[m];	
		for(int i_ = 0; i_ < m; ++i_) {
			int i = lst[i_].i, j = lst[i_].j;	
			i = rt(i), j = rt(j);
			if(i == j) continue;
			ext[i] = min(ext[i], lst[i_]);
			ext[j] = min(ext[j], lst[i_]);
		}
		for(int i = 0; i < n; ++i) {
			if(ext[i].k == inf) continue;
			if(jn(ext[i].i, ext[i].j)) {
				sum += ext[i].k;
				--cc;
			}
		}
	}
	cout << sum;
#ifdef LOCAL
	std::cerr << std::fixed << std::setprecision(5);
	std::cerr << std::endl << "Time elapsed: " << ((float)clock() / CLOCKS_PER_SEC) << "s." << std::endl;
#endif
	return 0;
}
