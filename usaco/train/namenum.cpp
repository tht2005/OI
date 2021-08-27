/*
ID: dangduo1
LANG: C++11
PROB: namenum
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "namenum"

int n,ok,a[15];
string num,s,t;
map<char,int>mp= {
                    {'A','0'},{'B','0'},{'C','0'},
                    {'D','1'},{'E','1'},{'F','1'},
                    {'G','2'},{'H','2'},{'I','2'},
                    {'J','3'},{'K','3'},{'L','3'},
                    {'M','4'},{'N','4'},{'O','4'},
                    {'P','5'},{'R','5'},{'S','5'},
                    {'T','6'},{'U','6'},{'V','6'},
                    {'W','7'},{'X','7'},{'Y','7'}
                };

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>num; n=SZ(num); FORE(c,num)c-=2;
    ifstream dict("dict.txt");
    t.resize(n);
    while(dict>>s){
        if(SZ(s)!=n)continue;
        rep(i,n)t[i]=mp[s[i]];
        if(t==num){
            cout<<s<<'\n';
            ok=1;
        }
    }
    if(!ok)cout<<"NONE"<<'\n';
    dict.close();
    return 0;
}
