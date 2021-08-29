/*
ID: dangduo1
LANG: C++11
PROB: crypt1
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "crypt1"

int avail[10];

inline int check(int a)
{
    for(;a>0;a/=10)if(!avail[a%10])return 0;
    return 1;
}

inline int len(int a)
{
    int ans=0;
    for(;a>0;a/=10)++ans;
    return ans;
}

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    while(n--){
        int x; cin>>x; avail[x]=1;
    }
    int res=0;
    FOR(x,100,999)if(check(x))
        FOR(y,10,99)if(check(y)){
            if(len(y%10*x)==3&&check(y%10*x)&&len(y/10*x)==3&&check(y/10*x)&&len(x*y)==4&&check(x*y))++res;
        }
    cout<<res<<'\n';
    return 0;
}
