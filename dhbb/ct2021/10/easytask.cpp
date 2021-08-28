#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,a,b,z) for(int i=(a),_b=(b),_z=(z);i<=_b;i+=_z)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef int64_t ll;
const int nmax=1000100;

int n;
vector<int>primes;
bool snt[nmax];
ll a[nmax],res,mn;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n; FOR(i,1,n)cin>>a[i];
    a[0]=0; FOR(i,1,n)a[i]+=a[i-1];
    memset(snt,1,sizeof(snt)); snt[0]=snt[1]=0;
    for(int i=2;i*i<=n;++i)if(snt[i]){
        for(int j=i*i;j<=n;j+=i)snt[j]=0;
    }
    FOR(i,2,n)if(snt[i])primes.push_back(i);
    res=a[primes[0]]-a[primes[0]-1]; mn=a[primes[0]-1];
    FORE(x,primes){
        mn=min(mn,a[x-1]);
        res=max(res,a[x]-mn);
    }
    cout<<res;
    return 0;
}
