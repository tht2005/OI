#include <bits/stdc++.h>
using namespace std;

const int nmax = 300030;
int n, m, res, u, v, a[nmax], s[nmax];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + (a[i] ^ 1);
    res = u = v = 0;
    for(int l = 0, r = 0, r2; r <= n;){
        while(r <= n && s[r] - s[l] <= m) ++r;
        r2 = r;
        if(r > n || s[r] - s[l] > m) --r2;
        if(res < r2 - l){
            res = r2 - l;
            u = l; v = r2;
        }
        while(l < r && s[r] - s[l] > m) ++l;
    }
    for(int i = u + 1; i <= v; ++i)
        a[i] = 1;
    cout << res << '\n';
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    return 0;
}
