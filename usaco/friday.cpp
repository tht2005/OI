/*
ID: dangduo1
LANG: C++11
PROB: friday
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "friday"

array<int,12>nday={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    int d=0;
    vector<int>res(7,0);
    for(int y=1900;y<1900+n;++y){
        rep(m,12){
            ++res[d];
            int extra=m==1&&y%4==0&&(y%400==0||y%100);
            d=(d+nday[m]+extra)%7;
        }
    }
    rep(i,6)cout<<res[i]<<' '; cout<<res[6]<<'\n';
    return 0;
}
