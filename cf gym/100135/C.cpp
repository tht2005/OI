
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()
#define TASK "knight"

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

int n,m;
ll dp[55][55];

int main()
{
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m;
	dp[1][1]=1;
	FOR(i,1,n)FOR(j,1,m){
		dp[i+2][j+1]+=dp[i][j];
		dp[i+1][j+2]+=dp[i][j];
	}
	cout<<dp[n][m];
	return 0;
}
