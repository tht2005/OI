#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef pair<int,int> ii;
const int nmax=1010;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int n,m,a[nmax][nmax],d[nmax][nmax];
queue<pair<int,ii> >q;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j];
    memset(d,0x3f,sizeof(d));
    FOR(i,1,n){
        d[i][1]=a[i][1]; d[i][m]=a[i][m];
        q.push({d[i][1],{i,1}});
        q.push({d[i][m],{i,m}});
    }
    FOR(j,1,m){
        d[1][j]=a[1][j]; d[n][j]=a[n][j];
        q.push({d[1][j],{1,j}});
        q.push({d[n][j],{n,j}});
    }
    while(!q.empty()){
        ii u=q.front().second; int du=q.front().first; q.pop();
        if(du!=d[u.first][u.second])continue;
        rep(i,4){
            ii v={u.first+dx[i],u.second+dy[i]};
            if(v.first<1||v.first>n||v.second<1||v.second>m)continue;
            if(d[v.first][v.second]>max(d[u.first][u.second],a[v.first][v.second])){
                d[v.first][v.second]=max(d[u.first][u.second],a[v.first][v.second]);
                q.push({d[v.first][v.second],v});
            }
        }
    }
    long long res=0;
    FOR(i,1,n)FOR(j,1,m)if(d[i][j]>a[i][j])res+=d[i][j]-a[i][j];
    cout<<res;
    return 0;
}
