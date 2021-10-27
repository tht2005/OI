/**
 *	Magician: tht2005
 *	Spawned: 2021.10.27 07:55:13	
**/

#include <bits/stdc++.h>
using namespace std;

// T = int_t, md is a prime number pls, uwu
template<typename T, T md>
struct mint
{
    T val;
 
    mint(T init = 0) : val(init) {}
 
    mint operator+ (mint rhs) { return mint(add(val, rhs.val)); }
    mint operator- (mint rhs) { return mint(sub(val, rhs.val)); }
    mint operator* (mint rhs) { return mint(mul(val, rhs.val)); }
    mint operator/ (mint rhs) { return mint(div(val, rhs.val)); }
 
    mint& operator= (T rhs) { val = rhs; return *this; }
    mint& operator+= (mint rhs) { val = add(val, rhs.val); return *this; }
    mint& operator-= (mint rhs) { val = sub(val, rhs.val); return *this; }
    mint& operator*= (mint rhs) { val = mul(val, rhs.val); return *this; }
    mint& operator/= (mint rhs) { val = div(val, rhs.val); return *this; }
 
    friend istream& operator>> (istream& is, mint& rhs) { return is >> rhs.val; }
    friend ostream& operator<< (ostream& os, mint rhs) { return os << rhs.val; }

    T power(T a, T b)
    {
        T res = 1;
        for(; b > 0; b >>= 1, a = mul(a, a))
            if(b & 1) res = mul(res, a);
        return res;
    }
 
    inline T add(T a, T b)
    {
        if((a += b) >= md) a -= md;
        return a;
    }
 
    inline T sub(T a, T b)
    {
        if((a -= b) < 0) a += md;
        return a;
    }
 
    inline T mul(T a, T b)
    {
        return 1ll * a * b % md;
    }

    inline T div(T a, T b)
    {
        return mul(a, power(b, md - 2));
    }
};

using MI = mint<int, (int)1e9>;

const int nmax = 500005;

int n, a[nmax], pm[nmax], pM[nmax], lc[nmax << 2], rc[nmax << 2];
MI res, sL[nmax << 2], sm[nmax << 2], sM[nmax << 2], smL[nmax << 2], sML[nmax << 2], smM[nmax << 2], smML[nmax << 2], lzL[nmax << 2], lzm[nmax << 2], lzM[nmax << 2];

void push(int x, int l, int r)
{
	if(lzL[x].val) {
		MI d_L = lzL[x];
		lzL[x] = 0;
		sL[x] += d_L * (r - l + 1);
		smL[x] += d_L * sm[x];
		sML[x] += d_L * sM[x];
		smML[x] += d_L * smM[x];
		if(l ^ r) {
			lzL[lc[x]] += d_L;
			lzL[rc[x]] += d_L;
		}
	}
	if(lzm[x].val) {
		MI new_m = lzm[x];
		lzm[x] = 0;
		sm[x] = new_m * (r - l + 1);
		smL[x] = new_m * sL[x];
		smM[x] = new_m * sM[x];
		smML[x] = new_m * sML[x];
		if(l ^ r) {
			lzm[lc[x]] = new_m;
			lzm[rc[x]] = new_m;
		}
	}
	if(lzM[x].val) {
		MI new_M = lzM[x];
		lzM[x] = 0;
		sM[x] = new_M * (r - l + 1);
		sML[x] = new_M * sL[x];
		smM[x] = new_M * sm[x];
		smML[x] = new_M * smL[x];
		if(l ^ r) {
			lzM[lc[x]] = new_M;
			lzM[rc[x]] = new_M;
		}
	}
}

void pull(int x)
{
	sL[x] = sL[lc[x]] + sL[rc[x]];
	sm[x] = sm[lc[x]] + sm[rc[x]];
	sM[x] = sM[lc[x]] + sM[rc[x]];
	smL[x] = smL[lc[x]] + smL[rc[x]];
	sML[x] = sML[lc[x]] + sML[rc[x]];
	smM[x] = smM[lc[x]] + smM[rc[x]];
	smML[x] = smML[lc[x]] + smML[rc[x]];
}

void inc_L(int x, int l, int r, int ql, int qr)
{
	push(x, l, r); if(qr < l || r < ql) return;
	if(ql <= l && r <= qr) {
		lzL[x] += 1;
		push(x, l, r);
	}
	else {
		int m = l + r >> 1;
		inc_L(x << 1, l, m, ql, qr);
		inc_L(x << 1 | 1, m + 1, r, ql, qr);
		pull(x);
	}
}

void setm(int x, int l, int r, int ql, int qr, int d)
{
	push(x, l, r);	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr) {
		lzm[x] = d;
		push(x, l, r);
	}
	else {
		int m = l + r >> 1;
		setm(x << 1, l, m, ql, qr, d);
		setm(x << 1 | 1, m + 1, r, ql, qr, d);
		pull(x);
	}
}

void setM(int x, int l, int r, int ql, int qr, int d)
{
	push(x, l, r); if(qr < l || r < ql) return;
	if(ql <= l && r <= qr) {
		lzM[x] = d;
		push(x, l, r);
	}
	else {
		int m = l + r >> 1;
		setM(x << 1, l, m, ql, qr, d);
		setM(x << 1 | 1, m + 1, r, ql, qr, d);
		pull(x);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for(int i = 1; i < 1000001; ++i) {
		lc[i] = i << 1;
		rc[i] = i << 1 | 1;
	}
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		pm[i] = i;
		while(pm[i] > 1 && a[i] < a[pm[i] - 1])
			pm[i] = pm[pm[i] - 1];
		pM[i] = i;
		while(pM[i] > 1 && a[i] > a[pM[i] - 1])
			pM[i] = pM[pM[i] - 1];
	}
	res = 0;
	for(int i = 1; i <= n; ++i) {
		inc_L(1, 1, n, 1, i);
		setm(1, 1, n, pm[i], i, a[i]);
		setM(1, 1, n, pM[i], i, a[i]);
		push(1, 1, n);
		res += smML[1];
	}
	cout << res;
	return 0;
}

/*** PRACTICE SOLVING SKILL, NOT USELESS SPELLS! x 3.14 ***/
