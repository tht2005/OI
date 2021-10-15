/**
 *	Magician: tht2005
 *	Spawned: 2021.10.15 22:05:15	
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll modulo = 1ll << 31;

class BalancedAirplane
{
public:
	struct node
	{
		int f;
		map<int, node*> c;
	};

	node* root;

	node* newnode()
	{
		node* p = new node;
		p->f = 0;
		return p;
	}

	void add(const vector<int>& a)
	{
		int n = a.size();
		node* p = root;
		for(int i = 0; i < n; ++i) {
			int nxt = a[i];
			if(!p->c.count(nxt)) {
				p->c[nxt] = newnode();
			}
			p = p->c[nxt];
		}
		++p->f;
	}

	int calc(const vector<int>& a)
	{
		node* p = root;
		int n = a.size();
		for(int i = 0; i < n; ++i) {
			if(!p->c.count(a[i]))
				return 0;
			p = p->c[a[i]];
		}
		return p->f;
	}

	ll count(int S, int R, vector<int> Aprefix)
	{
		vector<int> A(R);
		int L = Aprefix.size();
		for(int i = 0; i < L; ++i)
			A[i] = Aprefix[i];
		int state = Aprefix[L - 1];
		for(int i = L; i < R; ++i) {
			state = (state * 1103515245ll + 12345ll) % modulo;
			A[i] = state >> (31 - S);
		}
		if(S == 1) {
			return 1ll * R * (R + 1) / 2;
		}
		ll res = 0;
		root = newnode();
		vector<int> cnt(S, 0);
		vector<int> seq(S - 1, 0);
		add(seq);
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < S; ++j) {
				cnt[j] += A[i] >> j & 1;
			}
			vector<int> seq(S - 1, 0);
			for(int j = 0; j + 1 < S; ++j) {
				seq[j] = cnt[j] - cnt[j + 1];
			}
			res += calc(seq);
			add(seq);
		}
		return res;
	}
};
