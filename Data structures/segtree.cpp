#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define vi vector<ll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second

// recursive segtree with point update and range query
template<class T> struct segtree{
    ll n;
    T def = 0;
    vector<T> t;
    T comb(T a, T b){
        return a+b;
    }
    segtree(ll _n) : n(_n), t(4*_n, def){}

    T query(ll k, ll tl, ll tr, ll l, ll r){
        if(l>r)     return def;
        if(l==tl && r==tr)    return t[k];
        ll tm = (tl + tr) / 2;
        return comb(query(2*k, tl, tm, l, min(r, tm)), query(2*k+1, tm+1, tr, max(l, tm+1), r));
    }
    T q(ll l, ll r)    { return query(1, 0, n-1, l, r); }

    void update(ll k, ll tl, ll tr, ll pos, ll newVal){
        if(tl==tr)    t[k] = newVal;
        else{
            ll tm = (tl + tr) / 2;
            if(pos<=tm)     update(2*k, tl, tm, pos, newVal);
            else    update(2*k+1, tm+1, tr, pos, newVal);
            t[k] = comb(t[2*k], t[2*k+1]);
        }
    }
    void u(ll pos, ll val)    { update(1, 0, n-1, pos, val); }
};

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    return 0;
}
