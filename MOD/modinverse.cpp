template <typename T>
T inverse(T x, const T mod) {
    return modpow(x, mod - 2, mod);
}