/*
ID: dangduo1
LANG: C++11
PROB: gift1
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "gift1"

int n;
string s;
vector<string>order;
map<string,int>sum;

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    rep(i,n){
        cin>>s;
        order.push_back(s);
        sum[s]=0;
    }
    while(cin>>s){
        int g,p; cin>>g>>p;
        if(!p)continue;
        int val=g/p; sum[s]-=val*p;
        while(p--){
            cin>>s; sum[s]+=val;
        }
    }
    rep(i,n)cout<<order[i]<<' '<<sum[order[i]]<<'\n';
    return 0;
}
