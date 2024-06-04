#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

template<class T, auto cmp, size_t N>
struct heap {
	size_t n = 0;
	T a[N + 5];

	size_t left(size_t i) {
		return i << 1;
	}
	size_t right(size_t i) {
		return i << 1 | 1;
	}
	size_t parent(size_t i) {
		return i >> 1;
	}

	bool empty() {
		return (n == 0);
	}

	size_t siftup(size_t i) {
		assert(i <= n);
		while(i > 1) {
			size_t p = parent(i);
			if(!cmp(a[i], a[p])) {
				break;
			}
			swap(a[i], a[p]);
			i = p;
		}
		return i;
	}
	size_t siftdown(size_t i) {
		assert(i <= n);
		while(1) {
			size_t l = left(i), r = right(i);
			size_t largest = i;
			if(l <= n && cmp(a[l], a[largest])) {
				largest = l;
			}
			if(r <= n && cmp(a[r], a[largest])) {
				largest = r;
			}
			if(largest == i) {
				return i;
			}
			swap(a[i], a[largest]);
			i = largest;
		}
	}

	void heapify(T* b, size_t sz) {
		assert(sz <= N);
		n = sz;
		for(size_t i = 1; i <= n; ++i) {
			a[i] = b[i];
		}
		for(size_t i = n >> 1; i > 0; --i) {
			siftdown(i);
		}
	}

	T peek() {
		assert(n > 0);
		return a[1];
	}

	T pop() {
		assert(n > 0);
		T res = a[1];
		a[1] = a[n];
		--n;
		if(n > 0) {
			siftdown(1);
		}
		return res;
	}

	void push(T x) {
		++n;
		assert(n <= N);
		a[n] = x;
		siftdown(siftup(n));
	}
};

bool cmp(int a, int b) {
	return a < b;
}
