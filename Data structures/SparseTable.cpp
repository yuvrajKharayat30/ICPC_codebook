#include "bits/stdc++.h"
using namespace std;

using ll = long long;
#define vi vector<ll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second

template <class T> class Sparse{
    private:
    T comb(T a, T b) { return min(a, b); }

    ll lg(ll n) { return 63 - __builtin_clzll(n);}
    int n;
    vector<vector<T>> table;
    public:
    Sparse(vector<T> a){
        n = a.size();
        table = vector(lg(n)+1, vector<T>(n));
        table[0] = a;
        for(int j = 1; j<= lg(n); j++){
            for(int i = 0; i< n+1- (1<<j); i++){
                table[j][i] = comb(table[j-1][i], table[j-1][i+(1<<(j-1))]);
            }
        }
    }
    T query(int l, int r){
        assert(l<=r && 0<=l && r<n);
        int k = lg(r-l+1);
        return comb(table[k][l], table[k][r+1-(1<<k)]);
    }
};

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    int n, q; cin>>n>>q;
    vector<ll> a(n);
    for(ll &x: a) cin>>x;
    Sparse<ll> sp(a);
    while(q--){
        int l , r; cin>>l>>r, --l, --r;
        cout<<sp.query(l, r)<<'\n';
    }
    return 0;
}
