// use with modinverse and modpow

template <typename T>
T lagrange_interpolation(T xs, T ys, const long long m) {
    // mod m
    const ll n = xs.size();
    for(ll i = 0; i < n; i++) {
        xs[i] %= m;
        ys[i] %= m;
    }
    T all_c(n + 1);
    all_c[0] = 1;
    for(ll i = 0; i < n; i++) {
        T tmp(n + 1, 0);
        for(ll j = 0; j < n; j++) {
            tmp[j + 1] = all_c[j];
        }
        for(ll j = 0; j < n; j++) {
            tmp[j] = (m + tmp[j] - xs[i] * all_c[j] % m) % m;
        }
        all_c = move(tmp);
    }

    T c(n, 0);
    for(ll i = 0; i < n; i++) {
        ll qi = 1;
        for(ll j = 0; j < n; j++) {
            if(i == j) continue;
            qi = qi * (m + xs[i] - xs[j]) % m;
        }
        // qiの分母の部分の逆元とx_iのときの値y_iをかける．
        qi = inverse(qi, m) * ys[i] % m;

        auto tmp_c = all_c;
        for(ll j = n - 1; j >= 0; j--) {
            c[j] = (c[j] + qi * tmp_c[j + 1]) % m;
            tmp_c[j] = (tmp_c[j] + tmp_c[j + 1] * xs[i]) % m;
        }
    }
    return c;
}