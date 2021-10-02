
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

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
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<ll>dp(3,1),dp2(3,0);
	dp[0]=1;
	rep(_,n-1){
		dp2[0]=dp[0]+dp[1]+dp[2];
		dp2[1]=dp[1]+dp[2];
		dp2[2]=dp[0]+dp[1]+dp[2];
		swap(dp,dp2);
	}
	if(n)cout<<dp[0]+dp[1]+dp[2];
	else cout<<1;
	return 0;
}
