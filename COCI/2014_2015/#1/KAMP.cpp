#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "a"

typedef long long ll;
typedef pair<int,int> ii;
const int nmax=500050;

int n,k,a[nmax],sz[nmax];
ll dp[nmax];
vector<ii>adj[nmax];

void dfs(int u, int p=-1)
{
    dp[u]=0;
    sz[u]=a[u];
    FORE(x,adj[u]){
        if(x.second==p)continue;
        dfs(x.second,u);
        sz[u]+=sz[x.second];
        if(sz[x.second]){
            dp[u]+=dp[x.second]+x.first;
        }
    }
}

void dfs2(int u, int p=-1, ll sum=0)
{
    dp[u]+=sum;
    FORE(x,adj[u])if(x.second!=p){
        if(sz[u]>sz[x.second]){
            dfs2(x.second,u,sz[x.second]?dp[u]-dp[x.second]:dp[u]+x.first);
        }
        else{
            dfs2(x.second,u,sum);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>k;
    rep(i,n-1){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    rep(i,k){
        int x; cin>>x; a[x]=1;
    }
    dfs(1); dfs2(1);

    return 0;
}
