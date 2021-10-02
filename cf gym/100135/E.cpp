
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

int main()
{
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<int>a(200,-0x3f3f3f3f),c(200);
	cin>>a[1];
	FOR(i,2,n){
		fill(ALL(c),-0x3f3f3f3f);
		FOR(j,1,i){
			int b; cin>>b;
			ckmax(c[j],max(a[j],a[j-1])+b);
		}
		a.swap(c);
	}
	cout<<*max_element(ALL(a));
	return 0;
}
