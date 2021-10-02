
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()
#define TASK "king2"

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
	int a[15][15],dp[15][15];
	FOR(i,1,8)FOR(j,1,8)cin>>a[i][j];
	memset(dp,0x3f,sizeof(dp)); dp[8][1]=0;
	FORD(i,8,1)FOR(j,1,8){
		ckmin(dp[i-1][j],dp[i][j]+a[i-1][j]);
		ckmin(dp[i][j+1],dp[i][j]+a[i][j+1]);
		ckmin(dp[i-1][j+1],dp[i][j]+a[i-1][j+1]);
	}
	cout<<dp[1][8];
	return 0;
}
