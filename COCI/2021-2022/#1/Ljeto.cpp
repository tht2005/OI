/**
 *	Magician: KuriGohanKamehameha
 *	Spawned: 2021.10.16 21:01:54	
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int Q;
	cin >> Q;
	vector<int> lst(8, -20), score(2, 0);
	while(Q --> 0) {
		int t, a, b;
		cin >> t >> a >> b;
		--a; --b;
		score[a > 3] += 100;
		if(t - lst[a] <= 10) score[a > 3] += 50;
		lst[a] = t;
	}
	for(int i : score)
		cout << i << ' ';
	return 0;
}
