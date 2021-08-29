/*
ID: dangduo1
LANG: C++11
PROB: barn1
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "barn1"

int m,s,c,a[220],dp[220][55];

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>m>>s>>c;
    FOR(i,1,c)cin>>a[i]; sort(a+1,a+1+c);
    FOR(i,1,c)dp[i][1]=a[i]-a[1]+1;
    FOR(j,2,m){
        FOR(i,j,c){
            dp[i][j]=0x3f3f3f3f;
            FOR(k,j,i)dp[i][j]=min(dp[i][j],dp[k-1][j-1]+a[i]-a[k]+1);
        }
    }
    cout<<dp[c][min(m,c)]<<'\n';
    return 0;
}
