#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,a,b,z) for(int i=(a),_b=(b),_z=(z);i<=_b;i+=_z)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

const int MOD=777777777;
const int base=1000*1000*1000;
typedef vector<int> bigint;

char s[220];

inline istream& operator>>(istream& is, bigint& rhs)
{
    is>>s;
    rhs.clear();
    for(int i=strlen(s);i>0;i-=9){
        s[i]=0;
        rhs.push_back(atoi(i>=9?s+i-9:s));
    }
    while(SZ(rhs)>1&&rhs.back()==0)rhs.pop_back();
    return is;
}

inline void operator/=(bigint& a, int b)
{
    int carry=0;
    for(int i=SZ(a)-1;i>=0;--i){
        long long cur=a[i]+carry*1ll*base;
        a[i]=int(cur/b);
        carry=int(cur%b);
    }
    while(SZ(a)>1&&a.back()==0)a.pop_back();
}

inline bool isZero(const bigint& a)
{
    return a.empty()||(SZ(a)==1&&a.back()==0);
}

int n,cnt[30];
bigint S;

struct matrix
{
    vector<vector<int>>c;
    matrix(int type=0):c(26,vector<int>(26,0)) {
        if(type==0){
            FOR(i,0,25)c[i][i]=1;
        }
        else if(type==1){
            FOR(j,0,25)c[0][j]=cnt[j+1];
            FOR(i,1,25)c[i][i-1]=1;
        }
    }

    friend inline matrix operator*(matrix a, matrix b)
    {
        matrix res(-1);
        FOR(i,0,25)FOR(j,0,25)FOR(k,0,25)res.c[i][j]=(res.c[i][j]+1ll*a.c[i][k]*b.c[k][j])%MOD;
        return res;
    }

    friend matrix power(matrix a, bigint n)
    {
        matrix res;
        for(;!isZero(n);n/=2){
            if(n[0]&1)res=res*a;
            a=a*a;
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>S;
    FOR(i,1,n){
        int x; cin>>x; ++cnt[x];
    }
    cout<<power(matrix(1),S).c[0][0];
    return 0;
}
