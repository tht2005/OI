#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,a,b,z) for(int i=(a),_b=(b),_z=(z);i<=_b;i+=_z)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

int n,cnt;
bool vst[1010];
vector<int>child[1010],anc[1010];

void dfs(int u, int gotoanc, int gotochild)
{
    if(!vst[u])++cnt;
    vst[u]=1;
    if(gotoanc) FORE(v,anc[u])dfs(v,1,0);
    if(gotochild) FORE(v,child[u])dfs(v,0,1);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n; cin.ignore();
    string s;
    while(getline(cin,s)){
        if(s=="BLOOD")break;
        istringstream is(s);
        int x,y; is>>x>>y;
        child[y].push_back(x);
        anc[x].push_back(y);
    }
    int x; while(cin>>x)dfs(x,1,1);
    if(cnt==n)cout<<0;
    else FOR(i,1,n)if(!vst[i])cout<<i<<' ';
    return 0;
}
