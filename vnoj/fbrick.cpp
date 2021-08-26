#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

int a2,n,MOD,a,b;

struct matrix
{
    vector<vector<int>>c;
    matrix():c(4,vector<int>(4,0)) {}
    void reset(int type=0) {
        if(type==0){
            rep(i,4)rep(j,4)c[i][j]=i==j;
        }
        else if(type==1){
            rep(i,4)rep(j,4)c[i][j]=0;
            c[0][0]=c[0][2]=c[1][2]=c[2][1]=1;
            c[0][1]=c[1][1]=a;
            c[0][3]=c[1][3]=b;
            c[3][1]=2*a2%MOD;
            c[3][3]=MOD-1;
            /*
            c={
                {1,a,1,b},
                {0,a,1,b},
                {0,1,0,0},
                {0,2*a2%MOD,0,MOD-1}
            };
            */
        }
        else{
            rep(i,4)rep(j,4)c[i][j]=0;
        }
    }

    friend inline matrix operator*(matrix a, matrix b)
    {
        static matrix res; res.reset(-1);
        rep(i,4)rep(j,4)rep(k,4)res.c[i][j]=(res.c[i][j]+1ll*a.c[i][k]*b.c[k][j])%MOD;
        return res;
    }

    friend matrix power(matrix a, int n)
    {
        static matrix res; res.reset();
        for(;n>0;n>>=1){
            if(n&1)res=res*a;
            a=a*a;
        }
        return res;
    }
};

matrix mat1,mat;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin>>T;
    while(T--){
        cin>>a2>>n>>MOD;
        if(n==2){
            cout<<(1ll*a2*a2+1)%MOD<<'\n';
        }
        else if(n==3){
            int a3=(2ll*a2*a2+1ll*(MOD-1))%MOD;
            cout<<(1+1ll*a2*a2+1ll*a3*a3)%MOD<<'\n';
        }
        else{
            a=4ll*a2*a2%MOD;
            b=(4ll*MOD-4)*a2%MOD;
            int a3=(2ll*a2*a2+1ll*(MOD-1))%MOD;
            mat.reset(-1); mat1.reset(1);
            mat.c[0][0]=(1+1ll*a2*a2+1ll*a3*a3)%MOD;
            mat.c[1][0]=1ll*a3*a3%MOD;
            mat.c[2][0]=1ll*a2*a2%MOD;
            mat.c[3][0]=1ll*a2*a3%MOD;
            mat=power(mat1,n-3)*mat;
            cout<<mat.c[0][0]<<'\n';
        }
    }
    return 0;
}
