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

const int md=1000000007;
int n,x,dp[2][2020];

inline void add(int& a, int b)
{
	if((a+=b)>=md)a-=md;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>x;
	FOR(i,1,n)dp[1][i]=1;
	FOR(i,1,x-1){
		int cur=i&1,nxt=cur^1;
		FOR(j,1,n){
			for(int k=j;k<=n;k+=j)add(dp[nxt][k],dp[cur][j]);
			dp[cur][j]=0;
		}
	}
	int res=0;
	FOR(i,1,n)add(res,dp[x&1][i]);
	cout<<res;
	return 0;
}
