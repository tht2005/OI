#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

const int MOD=1000000007;

struct matrix
{
    array<array<int,3>,3>c;
    void reset(int type=0){
        if(type==0){
            rep(i,3)rep(j,3)c[i][j]=0;
            rep(i,3)c[i][i]=1;
        }
        else if(type==1){
            rep(i,3)rep(j,3)c[i][j]=0;
            c[0][0]=c[0][1]=1;
            c[1][1]=5;
            c[1][2]=c[2][1]=3;
            c[2][2]=2;
        }
        else{
            rep(i,3)rep(j,3)c[i][j]=0;
        }
    }
};

inline matrix operator*(matrix a, matrix b)
{
    static matrix res; res.reset(-1);
    rep(i,3)rep(j,3)rep(k,3)res.c[i][j]=(res.c[i][j]+1ll*a.c[i][k]*b.c[k][j])%MOD;
    return res;
}

matrix power(matrix a, long long n)
{
    static matrix res; res.reset();
    for(;n>0;n>>=1){
        if(n&1)res=res*a;
        a=a*a;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    matrix mat,mat1; mat1.reset(1);
    mat.c[0][0]=0; mat.c[1][0]=2; mat.c[2][0]=1;
    int T; cin>>T;
    while(T--){
        long long n; cin>>n;
        cout<<(power(mat1,n)*mat).c[0][0]<<'\n';
    }
    return 0;
}
