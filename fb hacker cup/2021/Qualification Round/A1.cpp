#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

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

const int MOD=1000000007;

template<typename A, typename B>
inline void add(A& a, B b)
{
    if((a+=b)>=MOD)a-=MOD;
}

typedef long long ll;

const string vovels="AEIOU";

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int>type(26);
    rep(i,26)if(vovels.find(i+'A')!=-1)type[i]=1; else type[i]=0;
    int T; cin>>T;
    FOR(t,1,T){
        string s; cin>>s;
        vector<int>cnt(26,0),cnt2(2,0);
        FORE(c,s)++cnt[c-'A'],++cnt2[type[c-'A']];
        int res=0x3f3f3f3f;
        rep(i,26)minimize(res,cnt2[type[i]^1]+2*(cnt2[type[i]]-cnt[i]));
        cout<<"Case #"<<t<<": "<<res<<'\n';
    }
    return 0;
}
