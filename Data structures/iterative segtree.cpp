#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define vi vector<ll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second

template <class T> class SegmentTree {
  private:
	const T DEFAULT = std::numeric_limits<T>().max();
	vector<T> segtree;
	int len;

  public:
	SegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
    T comb(T a, T b){
        return min(a, b);
    }
	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = comb(segtree[ind], segtree[ind ^ 1]);
		}
	}
	/** @return the minimum element in the range [start, end) */
	T range_min(int start, int end) {
		T val = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { val = comb(val, segtree[start++]); }
			if (end % 2 == 1) { val = comb(val, segtree[--end]); }
		}
		return val;
	}
};

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    

    return 0;
}