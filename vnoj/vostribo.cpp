#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef long long ll;
const ll MOD=1000000000000007ll;

inline ll mul(ll a, ll b)
{
    ll res=0;
    for(;b>0;b>>=1){
        if(b&1)res=(res+a)%MOD;
        a=(a<<1)%MOD;
    }
    return res;
}

struct matrix
{
    vector<vector<ll>>c;
    matrix(int type=0):c(4,vector<ll>(4,0)) {
        if(type==0){
            c={
                {1,0,0,0},
                {0,1,0,0},
                {0,0,1,0},
                {0,0,0,1}
            };
        }
        else if(type==1){
            c={
                {1,1,1,1},
                {0,1,1,1},
                {0,1,0,0},
                {0,0,1,0}
            };
        }
    }

    friend inline matrix operator*(matrix a, matrix b)
    {
        matrix res(-1);
        rep(i,4)rep(j,4)rep(k,4)res.c[i][j]=(res.c[i][j]+mul(a.c[i][k],b.c[k][j]))%MOD;
        return res;
    }

    friend matrix power(matrix a, int n)
    {
        matrix res;
        for(;n>0;n>>=1){
            if(n&1)res=res*a;
            a=a*a;
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        if(n<=3){
            cout<<n*(n+1)/2<<'\n';
        }
        else{
            matrix b(-1);
            b.c[0][0]=6; b.c[1][0]=3; b.c[2][0]=2; b.c[3][0]=1;
            b=power(matrix(1),n-3)*b;
            cout<<b.c[0][0]<<'\n';
        }
    }
    return 0;
}
