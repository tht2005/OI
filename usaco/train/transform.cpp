/*
ID: dangduo1
LANG: C++11
PROB: transform
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

#define TASK "transform"

int n;
char a[10][10],b[10][10],c[10][10];

void copy(char a[][10], char b[][10])
{
    rep(i,n)rep(j,n)a[i][j]=b[i][j];
}

bool match(char a[][10], char b[][10])
{
    rep(i,n)rep(j,n)if(a[i][j]!=b[i][j])return 0;
    return 1;
}

void turn(char a[][10], int deg)
{
    static char mem[10][10];
    rep(loop,deg/90){
        rep(i,n)rep(j,n)mem[i][j]=a[n-j-1][i];
        copy(a,mem);
    }
}

void reflect(char a[][10])
{
    rep(i,n)reverse(a[i],a[i]+n);
}

int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    rep(i,n)rep(j,n)cin>>a[i][j];
    rep(i,n)rep(j,n)cin>>b[i][j];
    FOR(t,1,5){
        copy(c,a);
        if(t<=3){
            turn(c,90*t);
        }
        else if(t==4){
            reflect(c);
        }
        else if(t==5){
            reflect(c);
            rep(i,3){
                turn(c,90);
                if(match(c,b)){
                    cout<<5<<'\n';
                    return 0;
                }
            }
        }
        if(match(c,b)){
            cout<<t<<'\n';
            return 0;
        }
    }
    if(match(a,b)){
        cout<<6<<'\n';
    }
    else{
        cout<<7<<'\n';
    }
    return 0;
}
