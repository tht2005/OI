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
inline bool maximize(A& a, B b)
{
    return a<b?a=b,1:0;
}

template<typename A, typename B>
inline bool minimize(A& a, B b)
{
    return a>b?a=b,1:0;
}

typedef long long ll;

int n;
ll a[1010];

int main()
{
if(fopen(TASK".inp","r")){
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
}
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n; FOR(i,1,n)cin>>a[i];
    ll res=0;
    for(int i=1;i<=n;i+=2){
        ll sum=0,mn=0;
        FOR(j,i+1,n){
            if(j%2){
                sum+=a[j];
            }
            else{
                res+=max(0ll,min(a[i]-mn,a[j]-sum-mn)+(j!=i+1));
                sum-=a[j];
                maximize(mn,-sum);
            }
        }
    }
    cout<<res;
    return 0;
}
