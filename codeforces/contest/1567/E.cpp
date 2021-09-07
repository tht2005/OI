
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

struct node
{
	int l,r,pre,suf,sz; ll sum;
}st[nmax<<2];

int n,q,a[nmax];

node comb(node a, node b)
{
	node res;
	res.l=a.l; res.r=b.r; res.sz=a.sz+b.sz;
	res.pre=a.pre==a.sz&&a.r<=b.l?a.sz+b.pre:a.pre;
	res.suf=b.suf==b.sz&&a.r<=b.l?a.suf+b.sz:b.suf;
	res.sum=a.sum+b.sum+(a.r<=b.l?1ll*a.suf*b.pre:0);	
	return res;
}

void build(int x, int l, int r)
{
	if(l^r){
		int m=l+r>>1;
		build(x<<1,l,m); build(x<<1|1,m+1,r);
		st[x]=comb(st[x<<1],st[x<<1|1]);
	}
	else{
		st[x]={a[l],a[l],1,1,1,1};
	}
}

void update(int i, int d, int x=1, int l=1, int r=n)
{
	if(i<l||r<i)return;
	if(l^r){
		int m=l+r>>1;
		update(i,d,x<<1,l,m); update(i,d,x<<1|1,m+1,r);
		st[x]=comb(st[x<<1],st[x<<1|1]);
	}
	else{
		st[x]={d,d,1,1,1,1};
	}
}

node query(int ql, int qr, int x=1,int l=1, int r=n)
{
	if(ql<=l&&r<=qr)return st[x];
	int m=l+r>>1;
	if(qr<=m)return query(ql,qr,x<<1,l,m);
	if(ql>m)return query(ql,qr,x<<1|1,m+1,r);
	return comb(query(ql,qr,x<<1,l,m),query(ql,qr,x<<1|1,m+1,r));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i];
	build(1,1,n);
	while(q--){
		int t,x,y; cin>>t>>x>>y;
		if(t==1)update(x,y);
		else cout<<query(x,y).sum<<'\n';
	}
	return 0;
}
