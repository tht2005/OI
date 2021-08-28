#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef long long ll;

#define TASK "a"

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

int d;
double c[12];

inline double f(double x)
{
    double sum=0,x2=1;
    FOR(i,0,d){
        sum+=x2*c[i];
        x2*=x;
    }
    return sum;
}

int main()
{
if(fopen(TASK".inp","r")){
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
}
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>d; FOR(i,0,d)cin>>c[i];
    double l=-1e6,r=1e6;
    if(f(l)>f(r))FOR(i,0,d)c[i]=-c[i];
    while(fabs(r-l)>1e-6){
        double x=(l+r)*0.5;
        if(f(x)>0)r=x; else l=x;
    }
    cout<<int((l+r)*500.);
    return 0;
}
