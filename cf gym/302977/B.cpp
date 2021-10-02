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

const int nmax=200020;
int n,k,avail[30];
string s;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>k>>s;
	while(k--){
		char c; cin>>c;
		avail[c-'a']=1;
	}
	ll res=0;
	int nxt=n;
	FORD(i,n-1,0){
		if(avail[s[i]-'a']){
			res+=nxt-i;
		}
		else{
			nxt=i;
		}
	}
	cout<<res<<'\n';
	return 0;
}
