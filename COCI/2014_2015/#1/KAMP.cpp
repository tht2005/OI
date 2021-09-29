#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using ll = long long;

const int nmax = 500050;
int n, k, col[nmax], near[nmax];
ll S, dp[nmax], dp2[nmax], far[nmax], dist[nmax];
vector<ii> adj[nmax];

void dfs(int u, int p)
{
	for(auto [w, v] : adj[u]) if(v ^ p) {
		dfs(v, u);
		if(col[v]) {
			col[u] = 1;
			S += w;
		}
	}
}

void dfs2(int u, int p)
{
	dp[u] = dp2[u] = 0;
	for(auto [w, v] : adj[u]) if(v ^ p && col[v]) {
		dfs2(v, u);
		if(dp[u] < dp[v] + w) {
			dp2[u] = dp[u];
			dp[u] = dp[v] + w;
		}
		else if(dp2[u] < dp[v] + w) {
			dp2[u] = dp[v] + w;
		}
	}
}

void dfs3(int u, int p, ll d)
{
	far[u] = max(d, dp[u]);
	for(auto [w, v] : adj[u]) if(v ^ p && col[v]) {
		if(dp[u] == dp[v] + w) {
			dfs3(v, u, w + max(d, dp2[u]));
		}
		else {
			dfs3(v, u, w + max(d, dp[u]));
		}
	}
}

void dfs4(int u, int p, ll f, int nr)
{
	dist[u] = f;
	near[u] = nr;
	for(auto [w, v] : adj[u]) if(v ^ p) {
		if(col[v]) {
			dfs4(v, u, 0, v);
		}
		else {
			dfs4(v, u, f + w, nr);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for(int i = 0; i + 1 < n; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}
	int r;
	while(k --> 0) {
		cin >> r;
		col[r] = 1;
	}
	S = 0;
	dfs(r, -1);
	dfs2(r, -1);
	dfs3(r, -1, 0);
	dfs4(r, -1, 0, r);
	for(int i = 1; i <= n; ++i) {
		cout << dist[i] + 2 * S - far[near[i]] << '\n'; 
	}
	return 0;
}
