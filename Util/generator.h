// Compatible with C++11 and above

#include<bits/stdc++.h>
#define _ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
#define endl "\n"
using namespace std;

static mt19937
rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){ // [l,r]
       return(uniform_int_distribution<int>(l, r)(rng));
}

namespace shuffles{
       template <class T> void shuffle_vector(vector<T>&v){
              shuffle(v.begin(), v.end(), rng);
       }
       template <class T> void shuffle_array(T arr[], int len){
              shuffle(arr, arr+len, rng);
       }
}
using namespace shuffles;

namespace util{
       vector<int> get_rand_perm(int n){ // return random permutation 1-n
              vector<int> ans;
              for(int i=1; i<=n; i++) ans.emplace_back(i);
              shuffle_vector(ans);
              return ans;
       }
       string output_file="none";
}
using namespace util;

namespace graphs{
       void tree(int n, int diameter, bool weighted=0, int lb_weight=0, int ub_weight=0){_
              int edge_index=0; array<int, 2> edges[n-1];
              for(int i=1; i<=diameter; ++i) edges[edge_index++]={i, i+1}; // placed diameter + 1 nodes [1, diameter+1] .. range for linking is now [2, diameter]
              int maxd[diameter+2], rem=n-(diameter+1);
              for(int i=1; i<=diameter+1; ++i) maxd[i]=min(i-1, (diameter+1)-i); // maxd[i] = maximum # nodes that can be added at i
              vector<vector<int>> depths[n+1]; // depths[i] contains table of available nodes for each depth .. it is monotonic .. 
              // depth[i][j] cannot exist if depth[i][j-1] does not..
              for(int i=2; i<=diameter; ++i) depths[i].push_back({i});
              for(int node=diameter+2; node<=n; ++node){ // placing node
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
              for(int j=0; j<2; ++j){
                     int p[n]; for(int i=0; i<n; ++i) p[i]=i+1; shuffle_array(p, n);
                     for(auto &i:edges){
                            i[0]=p[i[0]-1], i[1]=p[i[1]-1];
                            if(rand(0, 1)) swap(i[0], i[1]);
                     }
                     shuffle_array(edges, n-1);
              }
              if(output_file!="none"){
                     ofstream cout(output_file);
                     cout<<n<<endl;
                     for(auto i:edges) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
              }
              else{
                     cout<<n<<endl;
                     for(auto i:edges) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
              }
       }
       void functional_graph  (int n, bool weighted=0, int lb_weight=0, int ub_weight=0){_ // possible self loops
              int perm[n];
              for(int i=0; i<n; i++) perm[i]=i+1;
              shuffle_array(perm, n);
              array<int, 2> edges[n];
              int edge_index=0;
              for(int i=0; i<n; i++)  edges[edge_index++]={i+1, perm[i]};
              for(int j=0; j<2; j++){
                     int p[n]; for(int i=0; i<n; i++) p[i]=i+1; shuffle_array(p, n);
                     for(auto &i:edges){
                            i[0]=p[i[0]-1], i[1]=p[i[1]-1];
                            if(rand(0, 1)) swap(i[0], i[1]);
                     }
                     shuffle_array(edges, n);
              }
              if(output_file=="none"){
                     cout<<n<<endl;
                     for(auto i:edges) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
              }
              else{
                     ofstream cout(output_file);
                     cout<<n<<endl;
                     for(auto i:edges) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
              }
       }
       void raw_graph  (int n, int m, bool weighted=0, int lb_weight=0, int ub_weight=0){_ // possible edge repeats, cycles, self loops
              if(output_file=="none"){
                     cout<<n<<" "<<m<<endl;
                     for(int i=0; i<m; i++){
                            cout<<rand(1, n)<<" "<<rand(1, n)<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
                     }return;
              }
              ofstream cout(output_file);
              cout<<n<<" "<<m<<endl;
              for(int i=0; i<m; i++){
                     cout<<rand(1, n)<<" "<<rand(1, n)<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
              }
       }
       void clean_graph(int n, int m, bool weighted=0, int lb_weight=0, int ub_weight=0){_ // no edge repeats or self loops
              set<array<int, 2>> edges;
              while(edges.size()<m){
                     int a=rand(1, n);
                     int b=rand(1, n);
                     if(a>b) swap(a, b);
                     if(a==b || edges.count({a, b})) continue;
                     edges.insert({a, b});
              }
              vector<array<int,2>> e;
              for(auto i:edges){
                     if(rand(0, 1)) e.push_back({i[1], i[0]});
                     else e.push_back({i[0], i[1]});
              }
              shuffle_vector(e);
              if(output_file=="none"){
                     cout<<n<<" "<<m<<endl;
                     for(auto i:e) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
                     return;
              }
              ofstream cout(output_file);
              cout<<n<<" "<<m<<endl;
              for(auto i:e) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
       }
       void dag        (int n, int m, bool weighted=0, int lb_weight=0, int ub_weight=0){_
              vector<int> v=get_rand_perm(n);
              array<int, 2> edges[m];
              for(int i=0; i<m; i++){
                     int a=rand(0, n-1), b=rand(0, n-1);
                     while(a==b) a=rand(0, n-1), b=rand(0, n-1);
                     if(a>b) swap(a, b);
                     edges[i]={v[a], v[b]};
              }
              shuffle_array(edges, m);
              if(output_file=="none"){
                     cout<<n<<" "<<m<<endl;
                     for(auto i:edges) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
                     return;
              }
              ofstream cout(output_file);
              cout<<n<<" "<<m<<endl;
              for(auto i:edges) cout<<i[0]<<" "<<i[1]<<(weighted ? " "+to_string(rand(lb_weight, ub_weight)) : "")<<endl;
       }
}
using namespace graphs;

