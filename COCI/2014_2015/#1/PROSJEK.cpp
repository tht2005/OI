#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    vector<long long>b(n);
    rep(i,n){
        cin>>b[i]; b[i]*=i+1;
        cout<<(i?b[i]-b[i-1]:b[i])<<' ';
    }
    return 0;
}
