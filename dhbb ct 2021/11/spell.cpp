#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,a,b,z) for(int i=(a),_b=(b),_z=(z);i<=_b;i+=_z)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

struct state
{
    int k,i,j;
};

const int nmax=330;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int n,m,k,d[nmax][nmax][nmax];
char a[nmax][nmax];
queue<state>q;
string s;

int main()
{
#define TASK "spell"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m>>k>>s;
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j];
    memset(d,-1,sizeof(d));
    FOR(i,1,n)FOR(j,1,m){
        d[0][i][j]=0; q.push({0,i,j});
    }
    while(SZ(q)){
        int p=q.front().k,x=q.front().i,y=q.front().j; q.pop();
        if(p==k){
            cout<<d[p][x][y];
            return 0;
        }
        FOR(i,0,3){
            int u=x+dx[i],v=y+dy[i];
            if(u>0&&u<=n&&v>0&&v<=m){
                int lay=p; if(a[u][v]==s[p])++lay;
                if(d[lay][u][v]==-1){
                    d[lay][u][v]=d[p][x][y]+1;
                    q.push({lay,u,v});
                }
            }
        }
    }
    int res=d[k][1][1];
    FOR(i,1,n)FOR(j,1,m)res=min(res,d[k][i][j]);
    cout<<res;
    return 0;
}
