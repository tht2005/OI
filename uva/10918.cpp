#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<ll>f(31),g(31);
    f[0]=1; f[1]=0; g[0]=0; g[1]=1;
    FOR(i,2,30){
        f[i]=f[i-2]+2*g[i-1];
        g[i]=f[i-1]+g[i-2];
    }
    int n;
    while(scanf("%d\n",&n),~n)printf("%lld\n",f[n]);
    return 0;
}
