
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

template<class T, T inf, class cls>
struct segment_tree
{
	int n; vector<T>st; cls comb;
	
	segment_tree(const vector<T>& v)
	{
		n=SZ(v); st.resize(n<<1);
		rep(i,n)st[i+n]=v[i];
		FORD(i,n-1,1)st[i]=comb(st[i<<1],st[i<<1|1]);
	}

	T query(int l, int r)
	{
		T ans=inf;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)ans=comb(ans,st[l++]);
			if(r&1)ans=comb(ans,st[--r]);
		}
		return ans;
	}
};

class mx { public: ll operator()(ll a, ll b) { return max(a,b); } };
class mn { public: ll operator()(ll a, ll b) { return min(a,b); } }; 

int main()
{
if(fopen(TASK".inp","r")){
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);
	freopen("log.txt", "w", stderr);
}
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n,q; cin>>n>>q;
	vector<int>a(n),b(n); rep(i,n)cin>>a[i]; rep(i,n)cin>>b[i];
	vector<ll>s(n); rep(i,n)s[i]=(i?s[i-1]:0)+b[i]-a[i];
	segment_tree<ll,-inf,mx>f(s);
	segment_tree<ll,inf,mn>g(s);
	while(q--){
		int l,r; cin>>l>>r; --l; --r;
		if(s[r]^(l?s[l-1]:0)){
			cout<<-1<<'\n';
		}
		else{
			ll mn=g.query(l,r+1)-(l?s[l-1]:0),mx=f.query(l,r+1)-(l?s[l-1]:0);
			cout<<(mn<0?-1:mx)<<'\n';
		}
	}
	return 0;
}
