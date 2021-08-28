#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "a"

const int nmax=1000100;

int n,M,a[nmax];

int main()
{
if(fopen(TASK".inp","r")){
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
}
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>M; rep(i,n)cin>>a[i];
    int l=0,r=1e9,res=0;
    while(l<=r){
        int m=l+r>>1;
        int64_t sum=0; rep(i,n)if(a[i]>m)sum+=a[i]-m;
        if(sum>=M){
            res=m; l=m+1;
        }
        else{
            r=m-1;
        }
    }
    cout<<res;
    return 0;
}
