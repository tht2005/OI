#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

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

const int nmax=400040;
int n,root,sz[nmax],res[nmax];
vector<int>adj[nmax];

int dfs(int u, int p)
{
	sz[u]=1;
	FORE(v,adj[u])if(v^p)sz[u]+=dfs(v,u);
	return sz[u];
}

int find_centroid(int u, int p, int exp)
{
	FORE(v,adj[u])if((v^p)&&sz[v]>exp)return find_centroid(v,u,exp);
	return u;
}

void dfs2(int u, int p, int sum, int T)
{
	if(sum<=n/2||sz[u]+T>=n-n/2)res[u]=1;
	FORE(v,adj[u])if(v^p)dfs2(v,u,sum,T);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;
	rep(_,n-1){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	root=find_centroid(1,-1,dfs(1,-1)/2); res[root]=1;
	dfs(root,-1);
	int t=0,t2=0;
	FORE(u,adj[root]){
		if(t<sz[u])t2=t,t=sz[u];
		else if(t2<sz[u])t2=sz[u];
	}
	FORE(u,adj[root])dfs2(u,root,n-sz[u],sz[u]==t?t2:t);
	rep(i,n)cout<<res[i+1]<<' ';
	return 0;
}
