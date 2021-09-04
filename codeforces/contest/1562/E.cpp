#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "a"

int lcp[5050][5050],dp[5050];
char s[5050];

void solve()
{
    int n; cin>>n>>s;
    rep(i,n)lcp[i][n]=lcp[n][i]=0;
    FORD(i,n-1,0)FORD(j,n-1,0){
        if(i==j)lcp[i][j]=n-i;
        else if(s[i]==s[j])lcp[i][j]=lcp[i+1][j+1]+1;
        else lcp[i][j]=0;
    }
    int res=0;
    rep(i,n){
        dp[i]=n-i;
        rep(j,i){
            int c=lcp[i][j];
            if(i+c<n&&s[i+c]>s[j+c]){
                dp[i]=max(dp[i],dp[j]+n-i-c);
            }
        }
        res=max(res,dp[i]);
    }
    cout<<res<<'\n';
}

int main()
{
if(fopen(TASK".inp","r")){
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
}
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
