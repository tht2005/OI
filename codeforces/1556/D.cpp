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

long long ask(int i, int j)
{
    long long sum=0,x;
    cout<<"and"<<' '<<i<<' '<<j<<endl;
    cin>>x; sum+=x;
    cout<<"or"<<' '<<i<<' '<<j<<endl;
    cin>>x; sum+=x;
    return sum;
}

long long s[10010];

int main()
{
    int n,k; cin>>n>>k;
    long long a=ask(1,2),b=ask(2,3),c=ask(1,3);
    s[1]=(a+b+c)/2-b; s[2]=(a+b+c)/2-c; s[3]=(a+b+c)/2-a;
    FOR(i,4,n){
        int sum=ask(i-1,i);
        s[i]=sum-s[i-1];
    }
    sort(s+1,s+1+n); cout<<"finish"<<' '<<s[k]<<endl;
    return 0;
}
