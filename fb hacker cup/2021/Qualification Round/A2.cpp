#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef long long ll;

template<typename A, typename B>
inline bool maximize(A& a, B b)
{
    return a<b?a=b,1:0;
}

template<typename A, typename B>
inline bool minimize(A& a, B b)
{
    return a>b?a=b,1:0;
}

const int inf=0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin>>T;
    FOR(t,1,T){
        string s; cin>>s;
        vector<int>cnt(26,0); FORE(c,s)++cnt[c-'A'];
        vector<vector<int>>d(26,vector<int>(26,inf));
        rep(i,26)d[i][i]=0;
        int m; cin>>m;
        while(m--){
            char a,b; cin>>a>>b;
            minimize(d[a-'A'][b-'A'],1);
        }
        rep(k,26)rep(i,26)if(d[i][k]!=inf){
            rep(j,26)if(d[k][j]!=inf)minimize(d[i][j],d[i][k]+d[k][j]);
        }
        int res=inf;
        rep(c,26){
            int cost=0;
            rep(i,26)if(cnt[i]){
                if(d[i][c]==inf){
                    cost=inf; break;
                }
                cost+=cnt[i]*d[i][c];
            }
            minimize(res,cost);
        }
        cout<<"Case #"<<t<<": "<<(res==inf?-1:res)<<'\n';
    }
    return 0;
}
