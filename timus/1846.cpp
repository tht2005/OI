/**
 *	Author: tht2005
 *	Gene: 2021.11.26 22:53:23	
**/

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

#define PU_B push_back
#define PO_B pop_back
#define PU_F push_front
#define PO_F pop_front

#define FS first
#define SC second

#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()

int main()
{
	int Q;
	scanf("%d", &Q);
	std::vector<int> V;
	std::vector<std::pair<int, int>> q(Q);
	for(int i = 0; i < Q; ++i) {
		char c;
		scanf(" %c %d", &c, &q[i].SC);
		q[i].FS = (c == '+') ? 1 : -1;
		V.PU_B(q[i].SC);
	}
	sort(ALL(V));
	V.erase(std::unique(ALL(V)), V.end());
	int N = SZ(V);
	std::vector<int> cnt(N, 0), st(N << 1, 0);
	for(int i = 0; i < Q; ++i) {
		int d = q[i].FS, x = lower_bound(ALL(V), q[i].SC) - V.begin();
		cnt[x] += d;
		if(cnt[x] > 0) st[x + N] = V[x];
		else st[x + N] = 0;
		x += N;
		while(x >>= 1) {
			st[x] = std::__gcd(st[x << 1], st[x << 1 | 1]);
		}
		printf("%d\n", std::max(st[1], 1));
	}
	return 0;
}
