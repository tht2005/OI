#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "a"

typedef pair<int,int> ii;
const int nmax=10010;

int n,c[nmax],t[nmax];

int main()
{
if(fopen(TASK".inp","r")){
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
}
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n; rep(i,n)cin>>c[i]>>t[i],--c[i];
    int l=0,r=1e8,res=1e8;
    while(l<=r){
        int m=l+r>>1;
        int ptr=0,ok=1;
        vector<ii>v;
        rep(i,n)v.push_back({max(0,c[i]-m/t[i]),min(n-1,c[i]+m/t[i])});
        sort(ALL(v));
        priority_queue<int,vector<int>,greater<int>>pq;
        rep(i,n){
            for(;ptr<n&&v[ptr].first<=i;++ptr)pq.push(v[ptr].second);
            if(pq.empty()||i>pq.top()){
                ok=0; break;
            }
            pq.pop();
        }
        if(ok){
            res=m; r=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<res;
    return 0;
}
