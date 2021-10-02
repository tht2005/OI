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
typedef pair<int,int> ii;

struct rq
{
	int c,p,i;
	bool operator<(const rq& rhs) const { return c<rhs.c; }
};

const int nmax=1010;
int dp[nmax][nmax];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<rq>a(n);
	rep(i,n){
		cin>>a[i].c>>a[i].p;
		a[i].i=i;
	}
	sort(ALL(a));
	int k; cin>>k;
	vector<ii>b(k);
	rep(i,k){
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(ALL(b));
	rep(i,n)rep(j,k){
		dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		if(a[i].c<=b[j].first)ckmax(dp[i+1][j+1],dp[i][j]+a[i].p);
	}
	vector<ii>trace;
	for(int i=n-1,j=k-1;i>=0&&j>=0;){
		if(a[i].c<=b[j].first&&dp[i+1][j+1]==dp[i][j]+a[i].p){
			trace.push_back({a[i].i,b[j].second});
			--i; --j;
		}
		else if(dp[i+1][j+1]==dp[i][j+1]){
			--i;
		}
		else{
			--j;
		}
	}
	cout<<SZ(trace)<<' '<<dp[n][k]<<'\n';
	rep(i,SZ(trace))cout<<trace[i].first+1<<' '<<trace[i].second+1<<'\n';
	return 0;
}
