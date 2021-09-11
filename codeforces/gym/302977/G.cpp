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

const int inf =0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int v1,v2,t,d; cin>>v1>>v2>>t>>d;
	vector<int>dp(2020,-inf); dp[v1]=v1;
	rep(_,t-1){
		vector<int>dp2(2020,-inf);
		rep(i,2000)FOR(j,max(1,i-d),min(2000,i+d))ckmax(dp2[i],dp[j]+i);
		dp.swap(dp2);
	}
	cout<<dp[v2];
	return 0;
}
