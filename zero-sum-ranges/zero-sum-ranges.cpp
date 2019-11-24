template <typename T>
T zero_sum_ranges(vector<T> A) {
    T n = A.size();
    T sum[n + 1] = {};
    sum[1] = A[0];
    map<T, T> mp;
    for(size_t i = 0; i < n; i++) {
        sum[i + 1] = (sum[i] + A[i]) % k;
    }
    T ret = 0;
    for(size_t i = 0; i <= n; i++) {
        if(mp.count(sum[i])) ret += mp[sum[i]];
        mp[sum[i]]++;
    }
    cout << ret << endl;
}