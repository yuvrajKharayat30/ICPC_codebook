#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define vi vector<ll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second

struct DSU{
    vi parent, size;
    DSU(ll N){
        this->parent.resize(N);
        for(int i=0; i<N; i++)  parent[i]=i;
        this->size.resize(N, 1);
    }
    ll find(ll x){
        if(x==parent[x])    return x;
        return parent[x] = find(parent[x]);
    }
    bool sameSet(ll x, ll y){
        return  find(x) == find(y);
    }
    void unite(ll x, ll y){
        x = find(x); 
        y = find(y);
        if(x!=y){
            if(size[x]<size[y])     swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    

    return 0;
}