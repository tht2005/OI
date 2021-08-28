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

const int nmax=3030;
const ll inf=4557430888798830399ll;

struct dt
{
    int x,y,z;
    inline bool operator<(const dt& rhs) const { return y-z<rhs.y-rhs.z; }
};

int n;
ll dp[2][nmax],l[nmax],r[nmax];
dt a[nmax];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    FOR(i,1,n){
        cin>>a[i].x>>a[i].y>>a[i].z;
        a[i].y-=a[i].x; a[i].z-=a[i].x;
    }
    sort(a+1,a+1+n);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    FOR(i,1,n){
        int cur=i&1,pre=cur^1;
        l[i]=inf;
        FOR(j,0,i){
            dp[cur][j]=dp[pre][j];
            if(j)minimize(dp[cur][j],dp[pre][j-1]+a[i].y-j+1);
            minimize(l[i],dp[cur][j]);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[(n&1)^1][0]=0;
    FORD(i,n,1){
        int cur=i&1,pre=cur^1;
        r[i]=inf;
        FOR(j,0,n-i+1){
            dp[cur][j]=dp[pre][j];
            if(j)minimize(dp[cur][j],dp[pre][j-1]+a[i].z-j+1);
            minimize(r[i],dp[cur][j]);
        }
    }
    ll res=min(r[1],l[n]);
    FOR(i,1,n-1)minimize(res,l[i]+r[i+1]);
    FOR(i,1,n)res+=a[i].x;
    cout<<res;
    return 0;
}
