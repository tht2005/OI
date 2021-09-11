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

const int inf=0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<int>dp(1<<3,inf); dp[0]=0;
	rep(_,n){
		int c; string s; cin>>c>>s;
		int a=0; FORE(c,s)a|=1<<(c-'a');
		rep(mask,8)ckmin(dp[mask|a],dp[mask]+c);
	}
	cout<<(dp[7]==inf?-1:dp[7]);
	return 0;
}
