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

int calcxor(int n)
{
    if(n%4==0)return n;
    if(n%4==1)return 1;
    if(n%4==2)return n+1;
    return 0;
}

void solve()
{
    int a,b; cin>>a>>b;
    int sum=calcxor(a-1);
    if(sum==b){
        cout<<a<<'\n';
    }
    else{
        int need=sum^b;
        cout<<((need!=a)?a+1:a+2)<<'\n';
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
