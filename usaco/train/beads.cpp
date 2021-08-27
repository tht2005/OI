/*
ID: dangduo1
LANG: C++11
PROB: beads
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "beads"

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; string s; cin>>n>>s; s+=s;
    vector<int>a(n);
    int res=0;
    rep(i,n){
        char c='w';
        fill(ALL(a),0);
        for(int j=i;j>=0;--j){
            if(s[j]!='w'&&c!='w'&&s[j]!=c)break;
            if(s[j]!='w')c=s[j];
            a[j]=1;
        }
        c='w';
        for(int j=i+1;j<=i+n;++j){
            if(s[j]!='w'&&c!='w'&&s[j]!=c)break;
            if(s[j]!='w')c=s[j];
            a[j<n?j:j-n]=1;
        }
        res=max(res,accumulate(ALL(a),0));
    }
    cout<<res<<'\n';
    return 0;
}
