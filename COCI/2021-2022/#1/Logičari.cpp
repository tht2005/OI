/**
 *	Author: tht2005
 *	Gene: 2021.11.11 21:04:15	
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

const int N = 100010;
const int inf = (int)1e9;

namespace dsu
{
	int p[N];

	int root(int x)
	{
		return p[x] < 0 ? x : p[x] = root(p[x]);
	}

	int join(int x, int y)
	{
		if((x = root(x)) == (y = root(y)))
			return 0;
		if(p[y] < p[x])
			swap(x, y);
		p[x] += p[y];
		p[y] = x;
		return 1;
	}
}

int root, special, dp[N][2][2][2][2];
vt<int> adj[N];

int dfs(int u, int p, int i, int j, int rt, int sp)
{
	if(~dp[u][i][j][rt][sp])
		return dp[u][i][j][rt][sp];
	ll res = inf;
	bool valid = 1;
	if(u == root && i != rt) valid = 0;
	if(u == special && i != sp) valid = 0;
	if(u == special && j && rt) valid = 0;
	if(!valid)
		return dp[u][i][j][rt][sp] = res;
	bool nr = 0;
	if(j) nr = 1;
	if(u == root && sp) nr = 1;
	if(u == special && rt) nr = 1;
       	ll sum = i;
	for(int v : adj[u]) if(v != p) {
		sum += dfs(v, u, 0, i, rt, sp);
	}
	if(nr) {
		res = min(res, sum);
	}
	else {
		for(int v : adj[u]) if(v != p) {
			res = min(res, sum - dfs(v, u, 0, i, rt, sp) + dfs(v, u, 1, i, rt, sp));
		}
	}
	return dp[u][i][j][rt][sp] = res;
}

int main()
{
#ifndef LOCAL
#endif
	std::cin.tie(NULL)->sync_with_stdio(false);
	int n;
	cin >> n;
	fill(dsu::p + 1, dsu::p + 1 + n, -1);
	for(int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		if(dsu::join(u, v)) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		else {
			root = u;
			special = v;
		}
	}
	int res = inf;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			res = min(res, dfs(root, -1, i, 0, i, j));
		}
	}
	cout << (res == inf ? -1 : res);
	return 0;
}
