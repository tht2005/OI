
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()
#define TASK "longpath"

template<typename A, typename B>
inline bool ckmax(A& a, B b)
{
	return a<b?a=b,1:0;
}

template<typename A, typename B>
inline bool ckmin(A& a, B b)
{
	return a>b?a=b,1:0;
}

typedef long long ll;

int main()
{
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n,m; cin>>n>>m;
	vector<int>deg(n,0);
	vector<vector<int>>adj(n);
	while(m--){
		int x,y; cin>>x>>y; --x; --y;
		adj[x].push_back(y);
		++deg[y];
	}
	vector<int>tp;
	queue<int>q; rep(i,n)if(!deg[i])q.push(i);
	while(!q.empty()){
		int u=q.front(); q.pop();
		tp.push_back(u);
		FORE(v,adj[u])if(!(--deg[v]))q.push(v);
	}
	vector<int>dp(n,0);
	FORD(i,n-1,0)FORE(j,adj[tp[i]])ckmax(dp[tp[i]],dp[j]+1);
	cout<<*max_element(ALL(dp));
	return 0;
}
