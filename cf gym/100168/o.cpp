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
	
	bool operator== (pt rhs)
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator!= (pt rhs)
	{
		return x != rhs.x || y != rhs.y;
	}

	pt operator+ (pt rhs)
	{
		return pt(x + rhs.x, y + rhs.y);
	}

	pt operator- (pt rhs)
	{
		return pt(x - rhs.x, y - rhs.y);
	}

	pt operator* (double t)
	{
		return pt(x * t, y * t);
	}

	pt operator/ (double t)
	{
		return pt(x / t, y / t);
	}
};

pt operator* (double a, pt b)
{
	return b * a;
}

double dot(pt a, pt b)
{
	return a.x * b.x + a.y * b.y;
}

double cross(pt a, pt b)
{
	return a.x * b.y - a.y * b.x;
}

double norm(pt a)
{
	return dot(a, a);
}

double abs(pt a)
{
	return sqrt(norm(a));
}

pt solveSLE(pt a, pt b, pt c)
{
	double d = cross(a, b);
	return pt(cross(c, b) / d, cross(a, c) / d);
}

int main()
{
#ifndef LOCAL
	freopen("line3.in", "r", stdin);
	freopen("line3.out", "w", stdout);
#endif
	ll a, b, c, r;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &r);
	double val = 1. * r * hypot(a, b);
	printf("%lld %lld %.10lf\n", a, b, val + 1. * c);
	printf("%lld %lld %.10lf", a, b, 1. * c - val);
#ifdef LOCAL
	std::cerr << std::fixed << std::setprecision(5);
	std::cerr << std::endl << "Time elapsed: " << ((float)clock() / CLOCKS_PER_SEC) << "s." << std::endl;
#endif
	return 0;
}
