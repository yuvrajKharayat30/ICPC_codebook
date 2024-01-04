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

    T comb1(T a, T b)   { return max(a, b); }
    T comb2(T a, T b)   { return max(a, b); }
    segtree(){}
    segtree(ll n){
        def = 0;
        this->n =  n;
        v.resize(n);
        t.resize(4*n);
        lazy.resize(4*n);
    }

    void push(int k) {
        t[k*2] = comb2(t[k*2], lazy[k]);
        lazy[k*2] = comb2(lazy[k*2], lazy[k]);
        t[k*2+1] = comb2(t[k*2+1], lazy[k]);
        lazy[k*2+1] = comb2(lazy[k*2+1], lazy[k]);
        lazy[k] = 0;
    }

    T query(ll k, ll tl, ll tr, ll l, ll r){
        if (l > r)  return def;
        if (l == tl && tr == r) return t[k];
        push(k);
        ll tm = (tl + tr) / 2;
        return comb1(query(k*2, tl, tm, l, min(r, tm)), query(k*2+1, tm+1, tr, max(l, tm+1), r));
    }
    T q(ll l, ll r){
        return query(1, 0, n-1, l, r);
    }

    void update(ll k, ll tl, ll tr, ll l, ll r, T val){
        if (l > r) return;
        if (l == tl && tr == r) {
            t[k] = val;
            lazy[k] = val;
        }
        else{
            push(k);
            ll tm = (tl + tr) / 2;
            update(k*2, tl, tm, l, min(r, tm), val);
            update(k*2+1, tm+1, tr, max(l, tm+1), r, val);
            t[k] = comb1(t[k*2], t[k*2+1]);
        }
    }
    void u(ll l, ll r, T val){
        update(1, 0, n-1, l, r, val);
    }

};



struct HLD{
    vi parent, depth, sz, nxt, in, out;
    ll t;
    segtree<ll> seg;
    HLD(vector<vi> &adj) {
        ll n = adj.size();
        parent.resize(n+5, 0);
        depth.resize(n+5, 0);
        sz.resize(n+5, 0);
        nxt.resize(n+5, 0);
        in.resize(n+5, 0);
        out.resize(n+5, 0);
        seg = segtree<ll>(n+5);
        t = 1;
        dfs(1, adj);
        dfs_hld(1, adj);
    }
    void dfs(ll v, vector<vi> &adj){
        sz[v] = 1;
        for(int i=0; i<adj[v].size(); i++) {
            if(adj[v][i] != parent[v]){
                parent[adj[v][i]] = v;
                depth[adj[v][i]] = depth[v] + 1;
                dfs(adj[v][i], adj);
                sz[v] += sz[adj[v][i]];
                if(sz[adj[v][i]] > sz[adj[v][0]]) {
                    swap(adj[v][i], adj[v][0]);
                }
            }
        }
    }
    void dfs_hld(ll v, vector<vi> &adj) {
        in[v] = t++;
        for(auto u: adj[v]) {
            if(u!=parent[v]){
                nxt[u] = (u == adj[v][0] ? nxt[v] : u);
                dfs_hld(u, adj);
            }
        }
        out[v] = t;
    }
    // path update and query
    void update(ll x, ll y, ll val){
        while(nxt[x]!=nxt[y]){
            if(depth[nxt[x]] > depth[nxt[y]])   swap(x, y);
            seg.u(in[nxt[y]], in[y], val);
            y = parent[nxt[y]];
        }
        if(depth[x]>depth[y])   swap(x, y);
        seg.u(in[x], in[y], val);
    }
    ll query(ll x, ll y){
        ll res=0;
        while(nxt[x]!=nxt[y]){
            if(depth[nxt[x]] > depth[nxt[y]])   swap(x, y);
            res = max(res, seg.q(in[nxt[y]], in[y]));
            y = parent[nxt[y]];
        }
        if(depth[x]>depth[y])   swap(x, y);
        res = max(res, seg.q(in[x], in[y]));
        return res;
    }
    // subtree update and query
    void update2(ll x, ll val){
        seg.u(in[x], out[x], val);
    }
    ll query2(ll x){
        return seg.q(in[x], out[x]);
    }
};


signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    

    return 0;
}