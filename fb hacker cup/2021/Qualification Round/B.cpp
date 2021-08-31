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
        int n; cin>>n;
        vector<int>row(n);
        vector<vector<char>>a(n,vector<char>(n));
        rep(i,n)rep(j,n)cin>>a[i][j];
        int res=inf,way=0;
        rep(i,n){
            row[i]=count(ALL(a[i]),'X');
            if(count(ALL(a[i]),'O')>0)continue;
            int cnt=count(ALL(a[i]),'.');
            minimize(res,cnt);
        }
        rep(j,n){
            int cntO=0;
            rep(i,n)if(a[i][j]=='O')++cntO;
            if(cntO)continue;
            int cnt=0;
            rep(i,n)if(a[i][j]=='.')++cnt;
            minimize(res,cnt);
        }
        if(res==0){
            way=1;
        }
        else{
            rep(i,n){
                if(count(ALL(a[i]),'O')>0)continue;
                int cnt=count(ALL(a[i]),'.');
                if(res==cnt)++way;
            }
            rep(j,n){
                int cntO=0;
                rep(i,n)if(a[i][j]=='O')++cntO;
                if(cntO)continue;
                int cnt=0;
                rep(i,n)if(a[i][j]=='.')++cnt;
                if(res==cnt){
                    cnt=0;
                    rep(i,n)if(a[i][j]=='.'&&row[i]+1==n)++cnt;
                    if(cnt!=1)++way;
                }
            }
        }
        cout<<"Case #"<<t<<": ";
        if(res==inf)cout<<"Impossible";
        else cout<<res<<' '<<way;
        cout<<'\n';
    }
    return 0;
}
