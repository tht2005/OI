#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "a"

void solve()
{
    vector<int>isPrime(100,1); isPrime[0]=isPrime[1]=0;
    rep(i,100)if(isPrime[i])for(int j=i*i;j<100;j+=i)isPrime[j]=0;
    int n; cin>>n;
    string s; cin>>s;
    FORE(c,s){
        if(c=='1'||c=='4'||c=='6'||c=='8'||c=='9'){
            cout<<1<<'\n'<<c<<'\n';
            return;
        }
    }
    rep(i,n)FOR(j,i+1,n-1){

        if(!isPrime[(s[i]-48)*10+s[j]-48]){
            cout<<2<<'\n'<<s[i]<<s[j]<<'\n';
            return;
        }
    }
}

int main()
{
if(fopen(TASK".inp","r")){
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    freopen("log.txt", "w", stderr);
}
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
