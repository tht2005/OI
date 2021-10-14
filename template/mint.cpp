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
    friend ostream& operator<< (ostream& os, mint& rhs) { return os << rhs.val; }

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
        return 1ll * a * power(b, md - 2);
    }
};