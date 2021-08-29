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

int a[100010];

void solve()
{
    int n; cin>>n;
    int o=0,e=0;
    FOR(i,1,n){
        cin>>a[i];
        if(a[i]&1)++o; else ++e;
    }
    if(n&1){
        if(abs(o-e)!=1){
            cout<<-1<<'\n';
            return;
        }
        ll ans=0,pos;
        if(o>e){
            pos=1;
            FOR(i,1,n){
                if(a[i]&1){
                    ans+=abs(pos-i); pos+=2;
                }
            }
        }
        else{
            pos=1;
            FOR(i,1,n){
                if(!(a[i]&1)){
                    ans+=abs(pos-i); pos+=2;
                }
            }
        }
        cout<<ans<<'\n';
    }
    else{
        if(o!=e){
            cout<<-1<<'\n';
            return;
        }
        ll sum1=0,sum2=0,pos;
        pos=1;
        FOR(i,1,n){
            if(a[i]&1){
                sum1+=abs(pos-i); pos+=2;
            }
        }
        pos=1;
        FOR(i,1,n){
            if(!(a[i]&1)){
                sum2+=abs(pos-i); pos+=2;
            }
        }
        cout<<min(sum1,sum2)<<'\n';
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
