/*
ID: dangduo1
LANG: C++11
PROB: milk
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "milk"

typedef pair<int,int> ii;

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin>>n>>m;
    vector<ii>a(m); rep(i,m)cin>>a[i].first>>a[i].second;
    sort(ALL(a));
    int res=0;
    rep(i,m){
        if(n>a[i].second){
            res+=a[i].first*a[i].second;
            n-=a[i].second;
        }
        else{
            res+=n*a[i].first;
            break;
        }
    }
    cout<<res<<'\n';
    return 0;
}
