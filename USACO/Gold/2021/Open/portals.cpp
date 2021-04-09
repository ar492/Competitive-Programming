#include<bits/stdc++.h>
using namespace std;

// 1 index everything
const int sz=1e5+5;
int n, cost[sz];
vector<array<int, 2>> adj[sz][5]; // vertex, position is the state.. each state is adj to two nodes
bool vis[sz][5];
int cmps[sz][5];

namespace DSU{
       int par[sz], size[sz];
       void initialize(){ for(int i=0; i<n; i++) par[i]=i, size[i]=1; }
       int rep(int v){
              if (v==par[v]) return v;
              return par[v]=rep(par[v]);
       }
       void unite(int a, int b){
              a=rep(a); b=rep(b);
              if (size[a] < size[b]) swap(a, b);
              par[b]=a; size[a]+=size[b];
       }
}

namespace kruskals{
       struct edge{
              int u, v, w;
              bool operator<(const edge & other) const{ return w<other.w; } // sort by ascending weights
       };
       vector<edge> edges; int total;
}
using namespace DSU;
using namespace kruskals;

void dfs(int vertex, int pos, int cmp){
       vis[vertex][pos]=1;
       cmps[vertex][pos]=cmp;
       for(auto node:adj[vertex][pos]){
              if(!vis[node[0]][node[1]])
                     dfs(node[0], node[1], cmp);
       }
}

signed main(){
       cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);

       cin>>n;
       vector<array<int, 2>> portals[2*sz]; // locations of portals < vertex #, position 1-4 >
       for(int i=1; i<=n; i++){
              int p1,p2,p3,p4; cin>>cost[i]>>p1>>p2>>p3>>p4;
              portals[p1].push_back({i, 1}); portals[p2].push_back({i, 2}); portals[p3].push_back({i, 3}); portals[p4].push_back({i, 4});
       }

       map<int, int> opp; opp[1]=2; opp[2]=1; opp[3]=4; opp[4]=3;
       for(int i=1; i<=2*n; i++){ // 2n portals numbered 1-2n
              auto j=portals[i][0], k=portals[i][1];
              adj[j[0]][j[1]].push_back({k[0], k[1]});
              adj[k[0]][k[1]].push_back({j[0], j[1]});
              adj[j[0]][j[1]].push_back({j[0], opp[j[1]]});
              adj[k[0]][k[1]].push_back({k[0], opp[k[1]]});
       }
       int cmp=0;
       for(int vertex=1; vertex<=n; vertex++){
              for(int i=1; i<=4; i++){
                     if(!vis[vertex][i]){
                            dfs(vertex, i, cmp);
                            cmp++;
                     }
              }
       }
       for(int vertex=1; vertex<=n; vertex++){
              int c1=cmps[vertex][1], c2=cmps[vertex][2], c3=cmps[vertex][3], c4=cmps[vertex][4];
              if(c1==c2 && c2==c3 && c3==c4){}
              else if(c1==c2) edges.push_back({c1, c3, cost[vertex]});
              else if(c2==c3) edges.push_back({c1, c3, cost[vertex]});
              else if(c1==c3) edges.push_back({c1, c2, cost[vertex]});
       }
       initialize();
       sort(edges.begin(), edges.end());
       for(edge e:edges){
              if(rep(e.u)==rep(e.v)) continue;
              unite(e.u, e.v); total+=e.w;
       }
       cout<<total<<endl;
}
