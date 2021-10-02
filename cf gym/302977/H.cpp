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
	vector<int>s(n),c(n); rep(i,n)cin>>s[i]; rep(i,n)cin>>c[i];
	int res=inf;
	rep(i,n){
		int l=inf;
		rep(j,i)if(s[j]<s[i])ckmin(l,c[j]);
		if(l^inf){
			FOR(j,i+1,n-1)if(s[i]<s[j])ckmin(res,l+c[i]+c[j]);
		}
	}
	cout<<(res==inf?-1:res);
	return 0;
}
