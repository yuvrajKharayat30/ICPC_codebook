template<typename T> struct FenwickTree {
    vector<T> bit;
    long long n;

    FenwickTree(long long n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<T> const &a) : FenwickTree(a.size()){
        for (long long i = 0; i < n; i++) {
            bit[i] += a[i];
            long long r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }

    T sum(long long r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    T sum(long long l, long long r) {
        return sum(r) - sum(l - 1);
    }

    void add(long long idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
