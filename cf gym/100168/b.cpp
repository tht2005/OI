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
	freopen("angle2.in", "r", stdin);
	freopen("angle2.out", "w", stdout);
#endif
	pt a, b;
	scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
	printf("%.6lf", acos(a * b / abs(a) / abs(b)));
#ifdef LOCAL
	std::cerr << std::fixed << std::setprecision(5);
	std::cerr << std::endl << "Time elapsed: " << ((float)clock() / CLOCKS_PER_SEC) << "s." << std::endl;
#endif
	return 0;
}
