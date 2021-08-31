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

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    vector<int>a(n<<1);
    int res=0;
    rep(i,n<<1){
        cin>>a[i];
        int b; cin>>b;
        a[i]-=b; res+=b;
    }
    sort(ALL(a)); rep(i,n)res+=a[i];
    cout<<res;
    return 0;
}
