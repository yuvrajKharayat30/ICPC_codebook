#include "bits/stdc++.h"
using namespace std;

using ll = long long;
#define vi vector<ll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second


const ll SZ = (1ll<<35);

template<class T> struct node {
	T val = 0; node<T>* c[2];
    T comb(T a, T b) { return (a+b); }
    T cmb(node *nd1, node *nd2) { return comb( (nd1==NULL)?DEFAULT:nd1->val,(nd2==NULL)?DEFAULT:nd2->val );}
    T DEFAULT = 0;
	node() { c[0] = c[1] = NULL; }
	void update(ll ind, T v, ll L = 0, ll R = SZ-1) {
		if (L == ind && R == ind) { val = v; return; }
		ll M = (L+R)/2;
		if (ind <= M) {
			if (!c[0]) c[0] = new node();
			c[0]->update(ind,v,L,M);
		} else {
			if (!c[1]) c[1] = new node();
			c[1]->update(ind,v,M+1,R);
		}
        val = cmb(c[0], c[1]);
	}
	T query(ll lo, ll hi, ll L = 0, ll R = SZ-1) { // query sum of segment
		if (hi < L || R < lo) return DEFAULT;
		if (lo <= L && R <= hi) return val;
		ll M = (L+R)/2; T res = 0;
		if (c[0]) res += c[0]->query(lo,hi,L,M);
		if (c[1]) res += c[1]->query(lo,hi,M+1,R);
		return res;
	}
};


signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node<ll> rt;
    int q;
    cin>>q;
    while(q--){
        int t; cin>>t;
        if(t==1){
            ll ind, v; cin>>ind>>v, --ind;
            rt.update(ind, v);
        }else{
            ll l, r; cin>>l>>r, --l, --r;
            cout<<rt.query(l, r)<<'\n';
        }
    }

    return 0;
}
