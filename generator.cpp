// Compatible with C++11 and above

#include <bits/stdc++.h>
#define all(X) (X).begin(), (X).end()
#define 			_ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
#define nl "\n"
using namespace std;

static mt19937
rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){ // one rand integer in [l,r]
       uniform_int_distribution<int> ludo(l, r);
       return ludo(rng);
}

namespace shuffles{
       template <class T> void shuffle_vector(vector<T>&v){
              shuffle(all(v), rng);
       }
       template <class T> void shuffle_array(T arr[], int len){
              shuffle(arr, arr+len, rng);
       }
}
using namespace shuffles;

namespace graphs{
       void tree(int n, int diameter, bool weighted, int lb_weight=0, int ub_weight=0, string outputfile="none"){_
              int edge_index=0; array<int, 2> edges[n-1];
              for(int i=1; i<=diameter; i++) edges[edge_index++]={i, i+1}; // placed diameter + 1 nodes [1, diameter+1] .. range for linking is now [2, diameter]
              int maxd[diameter+2], rem=n-(diameter+1), available_parents[n+1];
              for(int i=1; i<=diameter+1; i++) maxd[i]=min(i-1, (diameter+1)-i); // maxd[i] = maximum # nodes that can be added at i
              vector<vector<int>> depths[n+1]; // depths[i] contains table of available nodes for each depth .. it is monotonic .. depth[i][j] cannot exist if depth[i][j-1] does not..
              for(int i=2; i<=diameter; i++) depths[i].push_back({i});
              for(int node=diameter+2; node<=n; node++){ // placing node
                     int ancestor=rand(2, diameter); // .. under ancestor
                     int max_depth=min(maxd[ancestor]-1, (int)depths[ancestor].size()-1);
                     int depth=rand(0, max_depth);
                     int parent=rand(0, depths[ancestor][depth].size()-1);
                     parent=depths[ancestor][depth][parent];
                     edges[edge_index++]={node, parent};
                     if(depths[ancestor].size()==depth+1) depths[ancestor].push_back({node});
                     else depths[ancestor][depth+1].emplace_back(node);
              }
              // shuffles and obfuscation
              for(int i=0; i<2; i++){
                     for(auto &i:edges) if(rand(0, 1)) swap(i[0], i[1]);
                     shuffle_array(edges, n-1);
              }
              if(outputfile!="none"){
                     ofstream cout(outputfile);
                     cout<<n<<nl;
                     for(auto i:edges) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<"\n";
              }
              else{
                     cout<<n<<nl;
                     for(auto i:edges) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<"\n";
              }
       }
       void functional_graph(int n, bool weighted, int lb_weight=0, int ub_weight=0, string outputfile="none"){_ // possible self loops
              int perm[n];
              for(int i=0; i<n; i++) perm[i]=i+1;
              shuffle_array(perm, n);
              array<int, 2> edges[n];
              int edge_index=0;
              for(int i=0; i<n; i++){
                     edges[edge_index++]={i+1, perm[i]};
              }
              for(int i=0; i<2; i++){
                     for(auto &i:edges) if(rand(0, 1)) swap(i[0], i[1]);
                     shuffle_array(edges, n);
              }
              if(outputfile=="none"){
                     cout<<n<<nl;
                     for(auto i:edges){
                            cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<"\n";
                     }
              }
              else{
                     ofstream cout(outputfile);
                     cout<<n<<nl;
                     for(auto i:edges){
                            cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<"\n";
                     }
              }
       }
       void raw_graph(int n, int m, bool weighted, int lb_weight=0, int ub_weight=0, string outputfile="none"){_ // n nodes, m edges, possible edge repeats, cycles, self loops..
              if(outputfile=="none"){
                     cout<<n<<" "<<m<<"\n";
                     for(int i=0; i<m; i++){
                            cout<<rand(1, n)<<" "<<rand(1, n)<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<"\n";
                     }return;
              }
              ofstream cout(outputfile);
              cout<<n<<" "<<m<<"\n";
              for(int i=0; i<m; i++){
                     cout<<rand(1, n)<<" "<<rand(1, n)<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<"\n";
              }
       }
       /*
       void binary_tree(){

       }
       void directed_acyclic_graph(int n, string outputfile="none"){_ // dag

       }
       void undirected_acyclic_graph(int n, string outputfile="none"){_

       }
       void raw_weighted_undirected_graph(int n, string outputfile="none"){_ // possible edge repeats, cycles, self loops..

       }
       void connected_graph(int n, string outputfile="none"){_

       }
       */

}
using namespace graphs;


signed main() {_

       tree(10, 5, true, 1, 100, "ouput.txt");
}