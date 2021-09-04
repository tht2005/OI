#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "a"

int a[300030];

void solve()
{
    int n,q; cin>>n>>q;
    FOR(i,1,n){
        char c; cin>>c;
        a[i]=a[i-1]+((c=='+')==(i&1)?1:-1);
    }
    while(q--){
        int l,r; cin>>l>>r;
        if(a[r]==a[l-1])cout<<0<<'\n';
        else if(l%2==r%2)cout<<1<<'\n';
        else cout<<2<<'\n';
    }
}

int main()
{
if(fopen(TASK".inp","r")){
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
}
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
