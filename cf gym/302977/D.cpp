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
	int n,k; cin>>n>>k;
	vector<int>a(n); rep(i,n)cin>>a[i];
	vector<int>s(n);
	rep(i,n){
		int t; cin>>t;
		s[i]=t?a[i]:0;
		if(i){
			s[i]+=s[i-1];
			a[i]+=a[i-1];
		}
	}
	int res=s[n-1];
	rep(i,n-k+1){
		int val=a[i+k-1]-(i?a[i-1]:0);
		if(i)val+=s[i-1];
		val+=s[n-1]-s[i+k-1];
		ckmax(res,val);
	}
	cout<<res;
	return 0;
}
