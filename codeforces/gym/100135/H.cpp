#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()
#define TASK "peacefulsets"

template<typename A, typename B>
inline bool ckmax(A& a, B b)
{
	return a<b?a=b,1:0;
}

template<typename A, typename B>
inline bool ckmin(A& a, B b)
{
	return a>b?a=b,1:0;
}

typedef long long ll;

int main()
{
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
	FOR(i,0,n)dp[0][i]=1;
	FOR(i,1,n){
		FOR(j,1,i)dp[i][j]=dp[i-j][j/2];
		FOR(j,1,n)dp[i][j]+=dp[i][j-1];
	}
	cout<<dp[n][n];
	return 0;
}
