/* 
ID: dangduo1 
LANG: C++11 
PROB: ride
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "ride"

int calc(string s)
{
    int res=1;
    FORE(c,s)res=res*(c-'A'+1)%47;
    return res;
}

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    string a,b; cin>>a>>b;
    cout<<(calc(a)==calc(b)?"GO":"STAY")<<'\n';
    return 0;
}
