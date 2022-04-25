#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
int n;
long long res;
char s[N];
int nNode, edge[N][26], link[N], len[N], f[N];

int main() {
    scanf("%s", s);
    n = strlen(s);
    len[0] = -1; link[0] = 0;
    len[1] = 0; link[1] = 0;
    nNode = 2;
    memset(edge, 0xff, sizeof(edge));
    for(int i = 0, cur = 0; i < n; ++i) {
        int c = s[i] - 'a', p = cur;
        while(s[i - 1 - len[p]] != s[i]) p = link[p];
        if(edge[p][c] == -1) {
            edge[p][c] = nNode;
            len[nNode] = len[p] + 2;
            int q = link[p];
            while(s[i - 1 - len[q]] != s[i]) q = link[q];
            if(p)
                link[nNode] = edge[q][c];
            else
                link[nNode] = 1;
            ++nNode;
        }
        cur = edge[p][c];
        ++f[cur];
    }
    res = 0;
    for(int i = nNode; i--; ) {
        f[link[i]] += f[i];
        res = max(res, (long long)len[i] * f[i]);
    }
    printf("%lld", res);
    return 0;
}
