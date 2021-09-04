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

struct line
{
    ll k,m;
    inline ll operator() (ll x) const { return k*x+m; }
};

struct linecontainer
{
    deque<line>hull;

    bool isect(const line& a, const line& b, const line& c)
    {
        return (b.m-a.m)*(a.k-c.k)>=(c.m-a.m)*(a.k-b.k);
    }

    void add(ll k, ll m)
    {
        line L={k,m};
        while(SZ(hull)>1&&isect(hull[SZ(hull)-2],hull[SZ(hull)-1],L))hull.pop_back();
        hull.push_back(L);
    }

    ll query(ll x)
    {
        while(SZ(hull)>1&&hull[0](x)>=hull[1](x))hull.pop_front();
        return hull[0](x);
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    vector<pair<int,int>>a(n);
    rep(i,n)cin>>a[i].first>>a[i].second; sort(ALL(a));
    int mx=a[n-1].second;
    FORD(i,n-2,0){
        if(a[i].second>mx)mx=a[i].second;
        else a[i].second=-1;
    }
    n=0; rep(i,SZ(a))if(~a[i].second)a[n++]=a[i]; a.resize(n);
    linecontainer s;
    ll dp=0;
    rep(i,n){
        s.add(a[i].second,dp);
        dp=s.query(a[i].first);
    }
    cout<<dp;
    return 0;
}
