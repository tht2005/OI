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
	freopen("intersec1.in", "r", stdin);
	freopen("intersec1.out", "w", stdout);
#endif
	pt p[3];
	scanf("%lf %lf %lf %lf %lf %lf", &p[0].x, &p[1].x, &p[2].x, &p[0].y, &p[1].y, &p[2].y);
	pt res = solveSLE(p[0], p[1], pt(0, 0) - p[2]);
	printf("%.10lf %.10lf", res.x, res.y);
#ifdef LOCAL
	std::cerr << std::fixed << std::setprecision(5);
	std::cerr << std::endl << "Time elapsed: " << ((float)clock() / CLOCKS_PER_SEC) << "s." << std::endl;
#endif
	return 0;
}
