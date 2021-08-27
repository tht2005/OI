/*
ID: dangduo1
LANG: C++11
PROB: milk2
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "milk2"

const int inf=0x3f3f3f3f;
typedef pair<int,int> ii;

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    vector<ii>a(n); rep(i,n)cin>>a[i].first>>a[i].second;
    sort(ALL(a)); a.push_back({inf,inf});
    int res=0,res2=0,mn=a[0].first,mx=a[0].second;
    for(int i=0;i<=n;++i){
        if(a[i].first>mx){
            res=max(res,mx-mn);
            if(i<n)res2=max(res2,a[i].first-mx);
            mn=a[i].first; mx=a[i].second;
        }
        else{
            mx=max(mx,a[i].second);
        }
    }
    cout<<res<<' '<<res2<<'\n';
    return 0;
}
