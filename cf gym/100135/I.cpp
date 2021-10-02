
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
	int S,n; cin>>S>>n;
	vector<int>dp(S+1,0);
	rep(_,n){
		int w; cin>>w;
		FORD(i,S,w)ckmax(dp[i],dp[i-w]+w);
	}
	cout<<dp[S];
	return 0;
}
