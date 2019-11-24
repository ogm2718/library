template <typename T>
T modpow(T x, T n, const T mod) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}