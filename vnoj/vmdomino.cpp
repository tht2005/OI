#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

int MOD,n,m,a[20][20],memo[20][20][1<<16];

inline void add(int&a, int b)
{
    if((a+=b)>=MOD)a-=MOD;
}

int dp(int i, int j, int mask)
{
    if(i>=n)return 1;
    int&res=memo[i][j][mask];
    if(res!=-1)return res;
    if(a[i][j]){
        res=dp(i+(j+1==m),j+1==m?0:j+1,(mask<<1)&((1<<m)-1));
    }
    else{
        res=0;
        rep(c,2){
            if((i+j)&1){
                if(i&&!a[i-1][j]&&c<(mask>>(m-1)&1))continue;
                if(j&&!a[i][j-1]&&c<(mask&1))continue;
            }
            else{
                if(i&&!a[i-1][j]&&c>(mask>>(m-1)&1))continue;
                if(j&&!a[i][j-1]&&c>(mask&1))continue;
            }
            add(res,dp(i+(j+1==m),j+1==m?0:j+1,((mask<<1)&((1<<m)-1))+c));
        }
    }
    return res;
}

void task1()
{
    int t; cin>>n>>m>>t;
    while(t--){
        int x,y; cin>>x>>y; a[x-1][y-1]=1;
    }
    memset(memo,-1,sizeof(memo));
    cout<<dp(0,0,0)<<'\n';
}

int sz,cnt,ok[2][300],id[300];
vector<int>vect;

struct matrix
{
    vector<vector<int>>c;
    matrix(int type=0):c(sz,vector<int>(sz,0)) {
        if(type==0){
            rep(i,sz)c[i][i]=1;
        }
        else if(type==1)
        {
            rep(m,sz){
                int mask=vect[m];
                if(!ok[1][mask])continue;
                rep(m2,sz){
                    int mask2=vect[m2];
                    if(!ok[0][mask2])continue;
                    int cont=1;
                    rep(j,n){
                        if(j&1){
                            if(!(mask>>j&1))continue;
                            if(!(mask2>>j&1)){
                                cont=0; break;
                            }
                        }
                        else{
                            if(mask>>j&1)continue;
                            if(mask2>>j&1){
                                cont=0; break;
                            }
                        }
                    }
                    c[id[mask]][id[mask2]]=cont;
                }
            }
        }
        else if(type==2){
            rep(m,sz){
                int mask=vect[m];
                if(!ok[0][mask])continue;
                rep(m2,sz){
                    int mask2=vect[m2];
                    if(!ok[1][mask2])continue;
                    int cont=1;
                    rep(j,n){
                        if(j&1){
                            if(mask>>j&1)continue;
                            if(mask2>>j&1){
                                cont=0; break;
                            }
                        }
                        else{
                            if(!(mask>>j&1))continue;
                            if(!(mask2>>j&1)){
                                cont=0; break;
                            }
                        }
                    }
                    c[id[mask]][id[mask2]]=cont;
                }
            }
        }
        //else all zero
    }

    friend inline matrix operator*(matrix a, matrix b)
    {
        matrix res(-1);
        rep(i,sz)rep(j,sz)rep(k,sz)add(res.c[i][j],1ll*a.c[i][k]*b.c[k][j]%MOD);
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

void task2()
{
    cin>>n>>m; sz=(1<<n);
    rep(mask,sz){
        ok[0][mask]=1;
        rep(i,n){
            if(i&1){
                if(mask>>i&1)continue;
                if((i&&(mask>>(i-1)&1))||(i+1<n&&(mask>>(i+1)&1))){
                    ok[0][mask]=0; break;
                }
            }
            else{
                if(!(mask>>i&1))continue;
                if((i&&!(mask>>(i-1)&1))||(i+1<n&&!(mask>>(i+1)&1))){
                    ok[0][mask]=0; break;
                }
            }
        }
    }
    rep(mask,sz){
        ok[1][mask]=1;
        rep(i,n){
            if(i&1){
                if(!(mask>>i&1))continue;
                if((i&&!(mask>>(i-1)&1))||(i+1<n&&!(mask>>(i+1)&1))){
                    ok[1][mask]=0; break;
                }
            }
            else{
                if(mask>>i&1)continue;
                if((i&&(mask>>(i-1)&1))||(i+1<n&&(mask>>(i+1)&1))){
                    ok[1][mask]=0; break;
                }
            }
        }
    }
    rep(mask,sz)if(ok[0][mask]||ok[1][mask])vect.push_back(mask);
    sz=SZ(vect);
    rep(i,sz)id[vect[i]]=i;
    matrix b(-1);
    rep(i,sz)b.c[i][0]=ok[0][vect[i]];
    b=power(matrix(2)*matrix(1),(m-1)/2)*b;
    if((m-1)&1)b=matrix(1)*b;
    int res=0;
    rep(i,sz)add(res,b.c[i][0]);
    cout<<res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>MOD; task1(); task2();
    return 0;
}
