#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

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

template<class T>
struct fenwick_tree
{
    int n;
    vector<T>f;

    fenwick_tree(int _n=0):n(_n),f(_n,0) {}

    void add(int x, int d)
    {
        for(;x<n;x=x|(x+1))f[x]+=d;
    }

    int get(int l, int r)
    {
        int res=0;
        for(;r>=0;r=(r&(r+1))-1)res+=f[r];
        for(--l;l>=0;l=(l&(l+1))-1)res-=f[l];
        return res;
    }

    // range increase point query
    void inc(int l, int r, int d=1)
    {
        add(l,d); add(r+1,-d);
    }

    int get(int i)
    {
        return get(0,i);
    }
};

struct edge
{
    int u,v,w;
    inline bool operator<(const edge& rhs) const { return w<rhs.w; }
};

struct query
{
    int t,i,a,b,c;
    inline bool operator<(const query& rhs) const { return c<rhs.c; }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,q; cin>>n>>q;
    vector<edge>edges;
    vector<vector<int>>adj(n);
    rep(_,n-1){
        int u,v,w; cin>>u>>v>>w; --u; --v;
        edges.push_back({u,v,w});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<query>queries;
    rep(_,q){
        char ch; cin>>ch;
        if(ch=='P'){
            int a,b,c; cin>>a>>b>>c;
            queries.push_back({0,_,a-1,b-1,c});
        }
        else{
            int k,c; cin>>k>>c;
            queries.push_back({1,_,0,k-1,c});
        }
    }
    sort(ALL(queries));
    int cnt=-1;
    vector<int>tin(n),tout(n);
    vector<vector<int>>p(n,vector<int>(17,-1));

    function<bool(int,int)>isanc=[&](int r, int c) -> bool
    {
        return tin[r]<=tin[c]&&tout[c]<=tout[r];
    };

    function<int(int,int)>lca=[&](int u, int v) -> int
    {
        if(tin[u]>tin[v])swap(u,v);
        if(isanc(u,v))return u;
        FORD(j,16,0)if(~p[v][j]&&!isanc(p[v][j],u))v=p[v][j];
        return p[v][0];
    };

    function<void(int,int)>dfs=[&](int u, int anc)
    {
        tin[u]=++cnt;
        p[u][0]=anc;
        FOR(j,1,16)if(~p[u][j-1])p[u][j]=p[p[u][j-1]][j-1];
        FORE(v,adj[u]){
            if(v==anc)continue;
            dfs(v,u);
        }
        tout[u]=cnt;
    };

    dfs(0,-1);
    fenwick_tree<int>f(n),g(n);
    vector<int>res(q);
    int ptr=0;
    vector<edge>elist(edges); sort(ALL(elist));

    for(int i=0,j=0;i<q;){
        query e;
        for(;j<q&&queries[i].c==queries[j].c;++j){
            e=queries[j];
            for(;ptr+1<n&&elist[ptr].w<=e.c;++ptr){
                int x=elist[ptr].u,y=elist[ptr].v;
                if(tin[x]>tin[y])swap(x,y);
                f.inc(tin[y],tout[y]);
                g.add(tin[y],1);
            }
        }
        for(;i<j;++i){
            e=queries[i];
            if(e.t){
                int id=e.b,u=edges[id].u,v=edges[id].v,w=edges[id].w;
                if(tin[u]<tin[v]){
                    res[e.i]=g.get(tin[v],tout[v])-(w<=e.c);
                }
                else{
                    res[e.i]=g.get(n-1)-g.get(tin[u],tout[u]);
                }
            }
            else{
                res[e.i]=f.get(tin[e.a])+f.get(tin[e.b])-(f.get(tin[lca(e.a,e.b)])<<1);
            }
        }
    }
    rep(i,q)cout<<res[i]<<'\n';
    return 0;
}
