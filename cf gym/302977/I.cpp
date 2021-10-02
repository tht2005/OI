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

int n,m,q,mx[550],a[550][550];
multiset<int>S;

void update(int r)
{
	if(~mx[r])S.erase(S.find(mx[r]));
	mx[r]=0;
	int cnt=0;
	rep(i,m+1){
		if(a[r][i]){
			++cnt;
		}
		else{
			ckmax(mx[r],cnt);
			cnt=0;
		}
	}
	S.insert(mx[r]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m>>q;
	memset(mx,-1,sizeof(mx));
	rep(i,n){
		rep(j,m)cin>>a[i][j];
		update(i);
	}
	while(q--){
		int i,j; cin>>i>>j; a[i-1][j-1]^=1;
		update(i-1);
		cout<<*(--S.end())<<'\n';
	}
	return 0;
}
