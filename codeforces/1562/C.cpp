#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "a"

void solve()
{
    int n; cin>>n;
    int last=0;
    FOR(i,1,n){
        char c; cin>>c;
        if(c=='0')last=i;
    }
    if(!last){
        cout<<1<<' '<<n-1<<' '<<2<<' '<<n<<'\n';
    }
    else if(last<=n/2){
        cout<<last<<' '<<n<<' '<<last+1<<' '<<n<<'\n';
    }
    else{
        cout<<1<<' '<<last<<' '<<1<<' '<<last-1<<'\n';
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
