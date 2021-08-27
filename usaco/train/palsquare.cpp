/*
ID: dangduo1
LANG: C++11
PROB: palsquare
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "palsquare"

int B;

string get(int n)
{
    string res;
    while(n>0){
        int c=n%B; n/=B;
        if(c<10)res.push_back(c+48);
        else res.push_back(c-10+'A');
    }
    reverse(ALL(res));
    return res;
}

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>B;
    FOR(i,1,300){
        string s=get(i*i),t=s; reverse(ALL(t));
        if(s==t)cout<<get(i)<<' '<<s<<'\n';
    }
    return 0;
}
