#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef long long ll;

template<typename A, typename B>
inline bool maximize(A& a, B b)
{
    return a<b?a=b,1:0;
}

template<typename A, typename B>
inline bool minimize(A& a, B b)
{
    return a>b?a=b,1:0;
}

typedef long long ll;

int n,d[55],p[55];
ll c[55];
vector<int>adj[55];

void dfs(int u, int anc=-1)
{
    p[u]=anc;
    FORE(v,adj[u]){
        if(v==anc)continue;
        c[v]+=c[u];
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

int lca(int u, int v)
{
    if(d[u]>d[v])swap(u,v);
    while(d[v]>d[u])v=p[v];
    while(u!=v)u=p[u],v=p[v];
    return u;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin>>T;
    FOR(t,1,T){
        cin>>n;
        FOR(i,1,n){
            cin>>c[i];
            adj[i].clear();
        }
        rep(m,n-1){
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        d[1]=0; dfs(1);
        ll res=0;
        FOR(i,1,n)FOR(j,1,n)if(lca(i,j)==1)maximize(res,c[i]+c[j]-c[1]);
        cout<<"Case #"<<t<<": "<<res<<'\n';
    }
    return 0;
}
