template<typename T, T md = 1000000007>
struct mint
{
    T val;
 
    mint(T init = 0) : val(init) {}
 
    T operator= (T rhs) { return val = rhs; }
 
    mint operator+ (mint rhs) { return mint(add(val, rhs.val)); }
    mint operator- (mint rhs) { return mint(sub(val, rhs.val)); }
    mint operator* (mint rhs) { return mint(mul(val, rhs.val)); }
 
    void operator+= (mint rhs) { val = add(val, rhs.val); }
    void operator-= (mint rhs) { val = sub(val, rhs.val); }
    void operator*= (mint rhs) { val = mul(val, rhs.val); }
 
    friend istream& operator>> (istream& is, mint& rhs) { return is >> rhs.val; }
    friend ostream& operator<< (ostream& os, mint& rhs) { return os << rhs.val; }
 
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
};