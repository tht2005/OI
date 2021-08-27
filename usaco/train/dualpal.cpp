/*
ID: dangduo1
LANG: C++11
PROB: dualpal
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "dualpal"

string get(int n, int B)
{
    string res;
    while(n>0){
        res.push_back(n%B+48);
        n/=B;
    }
    return res;
}

bool check(int n)
{
    int cnt=0;
    FOR(i,2,10){
        string s=get(n,i),t=s; reverse(ALL(t));
        if(s==t)++cnt;
    }
    return cnt>1;
}

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,S; cin>>n>>S;
    for(int i=S+1;n>0;++i)if(check(i)) { cout<<i<<'\n'; --n; }
    return 0;
}
