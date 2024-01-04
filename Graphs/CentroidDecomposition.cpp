#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define vi vector<ll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second


struct CentroidDecomposition{

    ll N;
    vector<ll> sz, par;
    vector<bool> removed;
    vector<vector<pair<ll, ll>>> ancestor_dists; 
    vector<vector<ll>> adj;

    CentroidDecomposition(vector<vector<ll>> &adj){
        this->adj = adj;
        this->N = adj.size()-1;
        sz.resize(N+1);
        par.resize(N+1);
        ancestor_dists.resize(N+1);
        removed.resize(N+1, false);
    }

    void get_size(ll u, ll p=0){
        sz[u] = 1;
        for(auto x: adj[u]){
            if(x!=p && !removed[x]){
                get_size(x, u);
                sz[u] += sz[x];
            }   
        }
    }

    ll get_centroid(ll u, ll s, ll p=0){
        for(ll x: adj[u]){
            if(x!=p && !removed[x]){
                if(sz[x] * 2 > s){
                    return get_centroid(x, s, u);
                }
            }
        }
        return u;
    }

    ll get_ancestor_dists(ll u, ll d, ll c, ll p=0){
        if(d)   ancestor_dists[u].push_back({c, d});
        for(ll x: adj[u]){
            if(x!=p && !removed[x]){
                get_ancestor_dists(x, d+1, c, u);
            }
        }
    }

    void build(ll u){
        get_size(u);
        ll centroid = get_centroid(u, sz[u]);
        get_ancestor_dists(centroid, 0, centroid);
        removed[centroid] = true;
        for(auto x: adj[centroid]){
            if(!removed[x]){
                build(x);
            }
        }
    }

};


signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    

    return 0;
}