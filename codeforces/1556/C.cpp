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
    cin>>n;
    FOR(i,1,n){
        cin>>a[i];
        if(!(i&1))a[i]=-a[i];
    }
    ll res=0;
    FOR(i,1,n){
        ll sum=a[i],minB=a[i];
        if(i&1){
            for(int j=i+1;j<=n;++j){
                if(a[i]<minB)break;
                if(!(j&1)){
                    ll l=max(0ll,sum+a[j]);
                    ll r=min({minB,sum-1,a[i]-1});
                    if(l<=r)res+=r-l+1;
                }
                sum+=a[j];
                minimize(minB,sum);
            }
        }
    }
    cout<<res;
    return 0;
}
