#include <bits/stdc++.h>
using namespace std;

class MaxMinTreeGame
{
	int n, res;
public:
	int findend(vector<int> edges, vector<int> costs)
	{	
		n = costs.size();	
		vector<int> deg(n, 0);
		for(int i = 0; i + 1 < n; ++i) {
			++deg[edges[i]];
			++deg[i + 1];
		}
		res = 0;
		for(int i = 0; i < n; ++i) {
			if(deg[i] == 1)
				res = max(res, costs[i]);
		}
		return res;
	}
};
