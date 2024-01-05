#include "bits/stdc++.h"
using namespace std;

using ll = long long;
#define vi vector<ll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second

struct scc {
  vector<vector<int>> adj, radj;
  vector<vector<int>> components;
  vector<bool> used;
  vector<int> order;
  int n;

  scc(int _n): n(_n), adj(_n), radj(_n){}

  void edge(int u, int v) {
    adj[u].push_back(v);
    radj[v].push_back(u);
  }

  void dfs1(int node) {
    used[node] = true;
    for (int x: adj[node])
      if(!used[x])
        dfs1(x);
    order.push_back(node);
  }

  void dfs2(int node) {
    used[node] = true;
    components.back().push_back(node);
    for (int x: radj[node])
      if (!used[x])
        dfs2(x);
  }

  vector<vector<int> > run() {
    components.clear();
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      if (!used[i]){
        dfs1(i);
      }
    }
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      int v = order[n - 1 - i];
      if (!used[v]) {
        components.push_back({});
        dfs2(v);
      }
    }
    return components;
  }
};



signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    scc graph(n);
    for(int i = 0; i<m; i++){
        int x, y; cin>>x>>y, --x, --y;
        graph.edge(x, y);
    }
    vector<vector<int>> component = graph.run();
    vector<int> ans(n);
    for(int j = 0; j<component.size(); j++){
        for(int x: component[j])
            ans[x] = j+1;
    }
    cout<<component.size()<<'\n';
    for(int x: ans) cout<<x<<' '; cout<<'\n';

    return 0;
}
