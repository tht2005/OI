#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

typedef vector<int> bigint;
const int base=1000*1000*1000;

void operator+=(bigint& a, const bigint& b)
{
    int carry=0;
    for(int i=0;i<max(SZ(a),SZ(b))||carry;++i){
        if(i==SZ(a))a.push_back(0);
        a[i]+=carry+(i<SZ(b)?b[i]:0);
        carry=a[i]>=base;
        if(carry)a[i]-=base;
    }
    while(SZ(a)>1&&a.back()==0)a.pop_back();
}

void print(const bigint& a)
{
    printf("%d",a.empty()?0:a.back());
    FORD(i,SZ(a)-2,0)printf("%09d",a[i]);
    puts("");
}

int main()
{
    vector<bigint>f(251);
    f[0]=f[1]=bigint(1,1);
    FOR(i,2,250){
        f[i]+=f[i-1];
        f[i]+=f[i-2];
        f[i]+=f[i-2];
    }
    int n;
    while(~scanf("%d\n",&n))print(f[n]);
    return 0;
}
