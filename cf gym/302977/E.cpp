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

const ll inf=0x3f3f3f3f3f3f3f3f;
const int nmax=1010;
int n,k,p,a[nmax],b[nmax<<1];
ll dp[nmax][nmax<<1];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>k>>p;
	FOR(i,1,n)cin>>a[i]; sort(a+1,a+1+n);
	FOR(i,1,k)cin>>b[i]; sort(b+1,b+1+k);
	ll res=inf;
	FOR(i,1,k-n+1){
		ll sum=0;
		FOR(j,i,i+n-1)ckmax(sum,abs(a[j-i+1]-b[j])+abs(b[j]-p));
		ckmin(res,sum);
	}
	cout<<res;
	return 0;
}
