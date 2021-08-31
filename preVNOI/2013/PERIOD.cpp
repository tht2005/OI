#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

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

const ll inf=1ll<<60;
int n,d,p,q,m;
ll a[10000010];
deque<ll>dq;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>d>>p>>q>>m;
    FOR(i,1,n)a[i]=1ll*p*i%m+q;
    FOR(i,1,n)a[i+n]=a[i];
    FOR(i,1,2*n)a[i]+=d*1ll*(i+1);
    ll res=inf;
    dq.push_back(0);
    FOR(i,1,2*n-1){
        while(!dq.empty()&&a[i]>dq.back())dq.pop_back();
        dq.push_back(a[i]);
        if(i>=n){
            if(dq.front()==a[i-n])dq.pop_front();
            minimize(res,dq.front()-1ll*d*(i-n+1));
        }
    }
    cout<<res;
    return 0;
}
