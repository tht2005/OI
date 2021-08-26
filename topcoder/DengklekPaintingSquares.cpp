#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

class DengklekPaintingSquares
{
public:
    static const int MOD=1000000007;
    int N,M,pow3[9],get3[6561][9],set3[6561][9][3],memo[101][6561];

    void init()
    {
        pow3[0]=1; FOR(i,1,8)pow3[i]=pow3[i-1]*3;
        rep(i,pow3[8])rep(j,9)get3[i][j]=(i/pow3[j])%3;
        rep(i,pow3[8])rep(j,9)rep(k,3)set3[i][j][k]=i+(k-get3[i][j])*pow3[j];
    }

    int dp(int i, int mask)
    {
        int&res=memo[i][mask];
        if(res!=-1)return res;
        if(i==N){
            rep(j,M)if(get3[mask][j]==1)return res=0;
            return res=1;
        }
        res=0;
        rep(config,1<<M){
            int next_mask=0;
            rep(j,M){
                if(config>>j&1){
                    if(get3[mask][j]==2){
                        next_mask=-1; break;
                    }
                    int cnt=0;
                    if(j&&(config>>(j-1)&1))++cnt;
                    if(j+1<M&&(config>>(j+1)&1))++cnt;
                    if(get3[mask][j])++cnt;
                    next_mask=set3[next_mask][j][(cnt&1)?1:2];
                }
                else{
                    if(get3[mask][j]==1){
                        next_mask=-1; break;
                    }
                }
            }
            if(next_mask!=-1)res=(res+dp(i+1,next_mask))%MOD;
        }
        return res;
    }

    int numSolutions(int n, int m)
    {
        N=n; M=m;
        init();
        memset(memo,-1,sizeof(memo));
        return dp(0,0);
    }
};
