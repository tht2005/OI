#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,x,y;
    int minx=110,maxx=0,miny=110,maxy=0;
    cin>>n;
    while(n--){
        cin>>x>>y;
        minx=min(minx,x); maxx=max(maxx,x);
        miny=min(miny,y); maxy=max(maxy,y);
    }
    int val=max(maxx-minx,maxy-miny);
    cout<<val*val;
    return 0;
}
