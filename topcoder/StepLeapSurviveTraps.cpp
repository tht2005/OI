#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod2 = 1ll << 31;

class StepLeapSurviveTraps
{
public:
    ll minDamage(int n, int j, int seed, int M)
    {
        vector<ll> T(n + 1);
        T[0] = 0;
        ll state = seed;
        for(int i = 1; i <= n; ++i) {
            state = (state * 1103515245ll % mod2 + 12345ll) % mod2;
            T[i] = 1 + (state % M);
        }
        deque<ll> d;
        for(int i = 0; i < n; ++i) {
            while(!d.empty() && T[i] < d.back()) d.pop_back();
            d.push_back(T[i]);
            if(i >= j && d.front() == T[i - j]) {
                d.pop_front();
            }
            T[i + 1] += d.front();
        }
        return T[n];
    }
};
