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

void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    string ans(n,'#');
    if(~s.find('U')){
        rep(i,n)if(s[i]=='U')ans[i]='D';
    }
    else{
        rep(i,n)if(s[i]=='D')ans[i]='U';
    }
    rep(i,n)if(ans[i]=='#')ans[i]='L',ans[i+1]='R';
    cout<<ans<<'\n';
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
