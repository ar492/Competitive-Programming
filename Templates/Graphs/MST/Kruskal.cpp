// https://cses.fi/problemset/task/1675/
#include<bits/stdc++.h>
#define int long long
#define pb push_back // replacing this with emplace_back doesn't work
using namespace std;
 
const int sz=1e6;
int n,m;
 
namespace DSU{
       int par[sz], size[sz];
       void initialize(){
              for(int i=0; i<n; i++) par[i]=i, size[i]=1;
       }
       int rep(int v){//finds the parent (representative) of a set
              if (v == par[v]) return v;
              return par[v] = rep(par[v]);
       }
       void unite(int a, int b){
              a = rep(a); b = rep(b);
              if(a != b){
                     if (size[a] < size[b]) swap(a, b);
                     par[b] = a; size[a] += size[b];
              }
       }
}
 
namespace IsThereMST{
       vector<int> adj[sz];
       bool vis[sz];
       void dfs(int node){
              vis[node]=true;
              for(int i:adj[node]) if(!vis[i]) dfs(i);
       }
       bool mst(){
              int cmp=0;
              for(int i=1; i<=n; i++){
                     if(vis[i]) continue;
                     dfs(i); cmp++;
              }
              return cmp==1;
       }
}
 
namespace kruskals{
       struct edge{
              int u, v, w;
              bool operator<(const edge & other) const{ return w<other.w; } // sort by ascending weights
       };
       vector<edge> edges; int total;
}
 
using namespace IsThereMST;
using namespace DSU;
using namespace kruskals;
 
signed main(){
       cin>>n>>m;
       while(m--){
              int u,v,w; cin>>u>>v>>w;
              adj[u].pb(v); adj[v].pb(u);
              edges.pb({u, v, w});
       }
       initialize();
 
       // kruskals
       sort(edges.begin(), edges.end());
       for(edge e:edges){
              if(rep(e.u)==rep(e.v)) continue;
              unite(e.u, e.v);
              total+=e.w;
       }
 
       if(!mst()) puts("IMPOSSIBLE");
       else cout<<total<<endl;
}
 
/*
from cph:
 
6 8
5 6 2
1 2 3
3 6 3
1 5 5
2 3 5
2 5 6
4 6 7
3 4 9
 
*/
