/**
 *	Author: tht2005
 *	Gene: 2021.11.02 15:10:09	
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef __GNU_PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#endif

#define fs first
#define sc second
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()

using ll = long long;
using pi = std::pair<int, int>;
template<typename T> using vt = std::vector<T>;

const double PI = acos(-1);

struct pt
{
	double x, y;

	pt() {}
	pt(double x_, double y_) : x(x_), y(y_) {}

	pt operator- (pt rhs)
	{
		return pt(x - rhs.x, y - rhs.y);
	}

	double operator* (pt rhs)
	{
		return x * rhs.x + y * rhs.y;
	}

	double operator^ (pt rhs)
	{
		return x * rhs.y - rhs.x * y;
	}
};

double norm(pt a)
{
	return a * a;
}

double abs(pt a)
{
	return sqrt(norm(a));
}

int main()
{
#ifndef LOCAL
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	vt<pt> a(n);
	for(int i = 0; i < n; ++i)
		scanf("%lf %lf", &a[i].x, &a[i].y);
	double sum = 0;
	for(int i = 1; i + 1 < n; ++i) {
		sum += (a[i] - a[0]) ^ (a[i + 1] - a[0]);	
	}
	sum = abs(sum) / 2.;
	printf("%.10lf", sum);
#ifdef LOCAL
	std::cerr << std::fixed << std::setprecision(5);
	std::cerr << std::endl << "Time elapsed: " << ((float)clock() / CLOCKS_PER_SEC) << "s." << std::endl;
#endif
	return 0;
}
