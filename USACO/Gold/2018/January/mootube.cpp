#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define int long long

struct query{
     int k,v,id;
     inline bool operator < (const query & other) const { return k > other.k; }
 };
 struct edge{
     int a,b,w;
     inline bool operator < (const edge & other) const { return w < other.w; } // for max pq
 };

const int _=(int)1e5+1;
int size[_], parent[_], answer[_], n, q;
vector<query> queries;

struct DSU{
     void init(){ for(int i=0; i<=n; i++){ parent[i]=i; size[i]=1; } }
     int rep(int v){
          if (v == parent[v]) return v;
          return parent[v] = rep(parent[v]);
     }
     void unite(int a, int b){
          a = rep(a); b = rep(b);
          if (a != b) {
             if (size[a] < size[b]) swap(a, b);
             parent[b] = a;
             size[a] += size[b];
          }
     }
};

signed main(){
    // ifstream cin("mootube.in"); ofstream cout("mootube.out");
     cin>>n>>q;
     priority_queue<edge> edges;
     for(int i=0; i<n-1; i++){
          int p,Q,r; cin>>p>>Q>>r;
          edges.push({p, Q, r});
     }
     for(int i=0; i<q; i++){
          int k,v; cin>>k>>v;
          queries.push_back({k, v, i});
     }
     sort(queries.begin(), queries.end());
     DSU dsu;
     dsu.init();
     for(query x:queries){
          while(edges.size() && edges.top().w>=x.k){
               dsu.unite(edges.top().a, edges.top().b);
               edges.pop();
          }
          answer[x.id]=size[dsu.rep(x.v)]-1;
     }
     for(int i=0; i<q; i++) cout<<answer[i]<<endl;
     return 0;
}




/*
silver version is naive bfs/dfs/ tree traversal in NQ time which is too slow
the key observation is that the queries can be sorted in decreasing  order of r
for a query, when you are traversing, whenever you encounter a weight smaller than r, you quit
- so when decreasing r, you add nodes
but where to add nodes from? - everywhere - everything is connected by components by dsu
size of a cmp is the answer for the query
but how to transition from query to query
- keep list of weights sorted in ascending order (max pq)
- keep iterating thru from the top until find a weight <= r
- then process the query and move to the next query
*/
