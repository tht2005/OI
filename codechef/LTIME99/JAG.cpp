#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef long long ll;

#define TASK "a"

template<typename A, typename B>
inline bool maximize(A& a, B b)
{
    return a<b?a=b,1:0;
}

template<typename A, typename B>
inline bool minimize(A& a, B b)
{
    return a>b?a=b,1:0;
}

int main()
{
if(fopen(TASK".inp","r")){
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
}
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        set<ll>st;
        rep(i,n){
            ll w; cin>>w;
            st.insert(w-i-1);
        }
        if(SZ(st)==1)cout<<n<<'\n';
        else cout<<1<<'\n';
    }
    return 0;
}
