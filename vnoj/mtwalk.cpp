#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

struct tri
{
    int u,v,i;
};

struct dsu
{
    struct dt
    {
        int u,pu,v,pv;
    };

    int n;
    vector<int>p,avail;
    vector<dt>v;
    dsu(int _n):n(_n),p(_n,-1),avail(_n,0) {}

    int root(int x)
    {
        return p[x]<0?x:root(p[x]);
    }

    int join(int x, int y)
    {
        if(!avail[x]||!avail[y]||(x=root(x))==(y=root(y)))return 0;
        if(p[y]<p[x])swap(x,y);
        v.push_back({x,p[x],y,p[y]});
        p[x]+=p[y];
        p[y]=x;
        return 1;
    }

    void add(const vector<tri>& a, int L)
    {
        FORE(x,a){
            if(avail[x.i])continue;
            v.push_back({x.i,-1,-1,-1});
            avail[x.i]=1;
            if(x.u>0)join(x.i,x.i-L);
            if(x.u<L-1)join(x.i,x.i+L);
            if(x.v>0)join(x.i,x.i-1);
            if(x.v<L-1)join(x.i,x.i+1);
        }
    }

    bool check()
    {
        return avail[0]&&avail[n-1]&&root(0)==root(n-1);
    }

    int time()
    {
        return SZ(v);
    }

    void roll_back(int t)
    {
        for(int cur=time();cur-->t;){
            if(v[cur].pu==-1){
                avail[v[cur].u]=0;
            }
            else{
                p[v[cur].u]=v[cur].pu;
                p[v[cur].v]=v[cur].pv;
            }
        }
        v.resize(t);
    }
};

const int nmax=100;

int n,a[nmax][nmax];
vector<tri>v[111];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    rep(i,n)rep(j,n){
        cin>>a[i][j];
        v[a[i][j]].push_back({i,j,i*n+j});
    }
    int low=a[0][0],high=a[n-1][n-1];
    if(low>high)swap(low,high);
    dsu d(n*n);
    FOR(i,low,high)d.add(v[i],n);
    int res=110;
    FORD(i,low,0){
        d.add(v[i],n);
        int backup=d.time();
        FOR(j,high,110){
            d.add(v[j],n);
            if(d.check()){
                res=min(res,j-i);
                break;
            }
        }
        d.roll_back(backup);
    }
    cout<<res;
    return 0;
}
