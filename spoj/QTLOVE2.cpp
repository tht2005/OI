#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

const int MOD=1000000007;

long long n;
int m;

struct matrix
{
    vector<vector<int>>c;
    matrix(int type=0) {
        if(type==0){
            c={
                {1,0},
                {0,1}
            };
        }
        else if(type==1){
            c={
                {m-2,m-1},
                {1,0}
            };
        }
        else{
            c={
                {0,0},
                {0,0}
            };
        }
    }

    friend inline matrix operator*(matrix a, matrix b)
    {
        matrix res(-1);
        rep(i,2)rep(j,2)rep(k,2)res.c[i][j]=(res.c[i][j]+1ll*a.c[i][k]*b.c[k][j])%MOD;
        return res;
    }

    friend matrix power(matrix a, long long n)
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
    cin>>n>>m;
    matrix b(-1); b.c[1][0]=m;
    b=power(matrix(1),n-1)*b;
    cout<<b.c[0][0];
    return 0;
}
