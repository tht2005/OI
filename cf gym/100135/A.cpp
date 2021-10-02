
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
const ll inf=1ll<<60;

int main()
{
    freopen("ladder.in","r",stdin);
    freopen("ladder.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<int>a(n+3); rep(i,n)cin>>a[i];
	vector<ll>dp(n+3,-inf); dp[0]=0;
	rep(i,n)rep(j,2)ckmax(dp[i+j+1],dp[i]+a[i+j]);
	cout<<dp[n];
	return 0;
}
