
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()
#define TASK "a"

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

const int inf=0x3f3f3f3f;

int main()
{
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL);
	vector<int>dp(300030,inf); dp[0]=0;
	int s=0,s2=0;
	for(int i=1;s<=300000;++i){
		s2+=i; s+=s2;
		FOR(j,s,300000)ckmin(dp[j],dp[j-s]+1);
	}
	int t; cin>>t;
	while(t--){
		int m; cin>>m;
		cout<<dp[m]<<'\n';
	}
	return 0;
}
