#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

const int nmax=500000;
int n,res,vst[nmax],a[nmax],deg[nmax];

void dfs(int u, int mafia)
{
    if(vst[u])return;
    vst[u]=1;
    if(mafia)++res;
    if(--deg[a[u]]==0||mafia)dfs(a[u],mafia^1);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    rep(i,n){
        cin>>a[i];
        --a[i]; ++deg[a[i]];
    }
    res=0;
    rep(i,n)if(!deg[i])dfs(i,1);
    rep(i,n)dfs(i,0);
    cout<<res;
    return 0;
}
