/**
 *	Author: tht2005
 *	Gene: 2021.11.07 16:37:36	
**/

#include <stdio.h>
#include <math.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define fs first
#define sc second
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()

const double inf = 1e6;
const double eps = 1e-9;

struct pt
{
	double x, y;

	pt(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

	pt& operator+= (const pt& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	pt& operator-= (const pt& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	pt& operator*= (double t) {
		x *= t;
		y *= t;
		return *this;
	}
	pt& operator/= (double t) {
		x /= t;
		y /= t;
		return *this;
	}

	pt operator+ (const pt& rhs) const {
		return pt(*this) += rhs;
	}
	pt operator- (const pt& rhs) const {
		return pt(*this) -= rhs;
	}
	pt operator* (double t) const {
		return pt(*this) *= t;
	}
	pt operator/ (double t) const {
		return pt(*this) /= t;
	}
};

pt operator* (double t, pt p) {
	return p * t;
}

double dot(pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

double cross(pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

double norm(pt a) {
	return dot(a, a);
}

double abs(pt a) {
	return sqrt(norm(a));
}

struct hf_pln
{
	pt p, pq;
	double angle;

	hf_pln() {}
	hf_pln(pt a, pt b) : p(a), pq(b - a) {
		angle = atan2(pq.y, pq.x);
	}

	bool out(const pt& r) {
		return cross(pq, r - p) < -eps;
	}
	bool operator< (const hf_pln& rhs) const {
		if(fabs(angle - rhs.angle) < eps) return cross(pq, rhs.p - p) < 0;
		return angle < rhs.angle;
	}
	bool operator== (const hf_pln& rhs) const {
		return fabs(angle - rhs.angle) < eps;
	}

	friend pt isect(const hf_pln& s, const hf_pln& t) {
		double alpha = cross(t.p - s.p, t.pq) / cross(s.pq, t.pq);
		return s.p + (alpha * s.pq);
	}
};

vector<pt> hp_isect(vector<hf_pln>& h)
{
	pt box[4] = {
		pt(inf, inf),
		pt(-inf, inf),
		pt(-inf, -inf),
		pt(inf, -inf)
	};
	for(int i = 0; i < 4; ++i) {
		h.push_back(hf_pln(box[i], box[(i + 1) % 4]));
	}
	sort(ALL(h));
	h.erase(unique(ALL(h)), h.end());
	int sz = 0;
	deque<hf_pln> d;
	for(int i = 0; i < SZ(h); ++i) {
		while(sz > 1 && h[i].out(isect(d[sz - 2], d[sz - 1]))) {
			--sz;
			d.pop_back();
		}
		while(sz > 1 && h[i].out(isect(d[0], d[1]))) {
			--sz;
			d.pop_front();
		}
		++sz;
		d.push_back(h[i]);
	}
	while(sz > 2 && d[0].out(isect(d[sz - 2], d[sz - 1]))) {
		d.pop_back();
		--sz;
	}
	while(sz > 2 && d[sz - 1].out(isect(d[0], d[1]))) {
		d.pop_front();
		--sz;
	}
	if(sz < 3)
		return vector<pt> ();
	vector<pt> poly;
	for(int i = 0; i + 1 < sz; ++i) {
		poly.push_back(isect(d[i], d[i + 1]));
	}
	poly.push_back(isect(d[sz - 1], d[0]));
	return poly;
}

int main()
{
#ifndef LOCAL
#endif
	int n;
	while(scanf("%d", &n), n) {
		vector<pt> p(n);
		for(int i = 0; i < n; ++i)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		vector<hf_pln> v;
		for(int i = 0; i < n; ++i)
			v.push_back(hf_pln(p[i], p[i + 1 < n ? i + 1 : 0]));
		if(hp_isect(v).empty())
			puts("0");
		else
			puts("1");
	}
	return 0;
}
