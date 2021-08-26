#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

class FloorBoards
{
public:
    const int inf=0x3f3f3f3f;
    int n,m,row[10],memo[10][1024];

    int dp(int i, int mask)
    {
        if(i==n)return 0;
        int&res=memo[i][mask];
        if(res!=-1)return res;
        res=inf;
        rep(config,1<<m){
            if(config&row[i])continue;
            int cost=0;
            rep(j,m){
                if(row[i]>>j&1)continue;
                if(config>>j&1){
                    if(!(mask>>j&1))++cost;
                }
                else{
                    if(!j)++cost;
                    else{
                        if(row[i]>>(j-1)&1)++cost;
                        else if(config>>(j-1)&1)++cost;
                    }
                }
            }
            res=min(res,dp(i+1,config)+cost);
        }
        return res;
    }

    int layout(vector<string>room)
    {
        n=SZ(room); m=SZ(room[0]);
        rep(i,n){
            row[i]=0;
            rep(j,m)if(room[i][j]=='#')row[i]|=(1<<j);
        }
        memset(memo,-1,sizeof(memo));
        return dp(0,0);
    }
};
