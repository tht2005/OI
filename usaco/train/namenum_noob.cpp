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
string s,t;
vector<string>name;

vector<vector<char>>dig={ {},{},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'} };

void Try(int i)
{
    rep(j,3){
        t.push_back(dig[a[i]][j]);
        if(i+1==n){
            if(binary_search(ALL(name),t))cout<<t<<'\n',ok=1;
        }
        else{
            Try(i+1);
        }
        t.pop_back();
    }
}

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    ifstream dict("dict.txt");
    while(dict>>s)name.push_back(s); dict.close();
    char c;
    while(cin>>c)a[n++]=c-48;
    Try(0);
    if(!ok)cout<<"NONE"<<'\n';
    return 0;
}
