#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void io(string in = "", string out = "", string err = "") {
if(fopen(in.c_str(), "r")) {
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
#ifdef conv_local
    freopen(err.c_str(), "w", stderr);
#endif
}
}
void conv();

int main() {
#ifdef conv_local
    //io("in.txt", "out.txt", "err.txt");
    auto st = chrono::steady_clock::now();
#else
#define TASKNAME ""
    io(TASKNAME".inp", TASKNAME".out");
#endif
    ios::sync_with_stdio(false); cin.tie(NULL);
    int Q = 1;
    //cin >> Q;
    while(Q--) {
        conv();
    }
#ifdef conv_local
    auto ed = chrono::steady_clock::now();
    cout << "\nExcution Time: " << chrono::duration_cast<chrono::milliseconds> (ed - st).count() << "[ms]" << endl;
#endif
    return 0;
}

const int N = 500;
int f[N][N];
void add(int x, int y_, int d) {
    for(; x < N; x |= x + 1) for(int y = y_; y < N; y |= y + 1) f[x][y] += d;
}
int query(int x, int y_) {
    int ret = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1) for(int y = y_; y >= 0; y = (y & (y + 1)) - 1) ret += f[x][y];
    return ret;
}
const int LIM = 1000000000;
void conv() {
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int>> a;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            a.emplace_back(x, i, j);
        }
    }
    sort(a.begin(), a.end());
    vector<int> x1(q), y1(q), x2(q), y2(q), k(q), l(q), r(q);
    for(int i = 0; i < q; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> k[i];
        ----x1[i];
        ----y1[i];
        --x2[i];
        --y2[i];
        l[i] = 0;
        r[i] = LIM + 1;
    }
    while(1) {
        vector<tuple<int, int>> work;
        for(int i = 0; i < q; ++i) {
            if(l[i] != r[i]) {
                int m = (l[i] + r[i]) >> 1;
                work.emplace_back(m, i);
            }
        }
        if(work.empty()) break;
        sort(work.begin(), work.end());
        memset(f, 0, sizeof(f));
        auto it = a.begin();
        for(auto [m, i] : work) {
            for(; it != a.end() && get<0>(*it) <= m; ++it) {
                add(get<1>(*it), get<2>(*it), 1);
            }
            if(query(x2[i], y2[i]) - query(x1[i], y2[i]) - query(x2[i], y1[i]) + query(x1[i], y1[i]) < k[i]) l[i] = m + 1;
            else r[i] = m;
        }
    }
    for(int i = 0; i < q; ++i) cout << l[i] << '\n';
}
