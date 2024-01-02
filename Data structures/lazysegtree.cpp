#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define vi vector<ll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second



template<class T> struct segtree{

    ll n, def;
    vector<T> v, t, lazy;

    T comb_min(T a, T b)    { return min(a, b); }
    T comb_add(T a, T b)    { return a+b; }
    void set_def()      { def = 1e18; }

    segtree(ll n){
        set_def();
        this->n =  n;
        t.resize(4*n);
        lazy.resize(4*n);
    }

    void push(int k) {
        t[k*2] = comb_add(t[k*2], lazy[k]);
        lazy[k*2] = comb_add(lazy[k*2], lazy[k]);
        t[k*2+1] = comb_add(t[k*2+1], lazy[k]);
        lazy[k*2+1] = comb_add(lazy[k*2+1], lazy[k]);
        lazy[k] = 0;
    }

    T query(ll k, ll tl, ll tr, ll l, ll r){
        if (l > r)
            return def;
        if (l == tl && tr == r)
            return t[k];
        push(k);
        ll tm = (tl + tr) / 2;
        return comb_min(query(k*2, tl, tm, l, min(r, tm)), query(k*2+1, tm+1, tr, max(l, tm+1), r));
    }

    T q(ll l, ll r){
        return query(1, 0, n-1, l, r);
    }

    void update(ll k, ll tl, ll tr, ll l, ll r, T addVal){
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[k] = comb_add(t[k], addVal);
            lazy[k] = comb_add(lazy[k], addVal);
        }
        else{
            push(k);
            ll tm = (tl + tr) / 2;
            update(k*2, tl, tm, l, min(r, tm), addVal);
            update(k*2+1, tm+1, tr, max(l, tm+1), r, addVal);
            t[k] = comb_min(t[k*2], t[k*2+1]);
        }
    }

    void u(ll l, ll r, T val){
        update(1, 0, n-1, l, r, val);
    }

};


signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    return 0;
}