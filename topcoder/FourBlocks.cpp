#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

class FourBlocks
{
public:
    const int inf=0x3f3f3f3f;
    int n,m,col[25],memo[25][1024];

    int dp(int j, int mask)
    {
        if(j==m)return mask?-inf:0;
        if(mask&col[j])return -inf;
        int&res=memo[j][mask];
        if(res!=-1)return res;
        res=0;
        rep(config,1<<(n-1)){
            if((config&(config<<1))||(col[j]&(config|(config<<1)))||(mask&(config|(config<<1))))continue;
            res=max(res,dp(j+1,config|(config<<1))+__builtin_popcount(config)*16+(n-__builtin_popcount(mask|config|(config<<1))));
        }
        return res;
    }

    int maxScore(vector<string>grid)
    {
        n=SZ(grid); m=SZ(grid[0]);
        memset(memo,-1,sizeof(memo));
        rep(j,m){
            col[j]=0;
            rep(i,n)if(grid[i][j]=='1')col[j]|=1<<i;
        }
        return dp(0,0);
    }
};
