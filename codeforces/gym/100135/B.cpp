
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()
#define TASK "lepus"

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
	int n; string s; cin>>n>>s;
	vector<int>dp(n,-1),d={1,3,5};
	dp[0]=0;
	rep(i,n)if(s[i]!='w'&&(~dp[i])){
		FORE(j,d){
			if(i+j<n&&s[i+j]!='w')ckmax(dp[i+j],dp[i]+(s[i+j]=='"'));
		}
	}
	cout<<dp[n-1];
	return 0;
}
