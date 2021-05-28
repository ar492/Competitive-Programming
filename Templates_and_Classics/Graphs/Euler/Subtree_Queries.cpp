// https://cses.fi/problemset/task/1137

/*

there is a tree with values in each node. There are queries which are either: update the value of a node, or print the sum of values in a subtree.
done with tree flattening / euler tour technique https://codeforces.com/blog/entry/81527

*/


#include<bits/stdc++.h>
#define time timeee
#define int long long
using namespace std;
 
struct euler{ int node, size; };
const int sz=2e5+1;
int n, q, time, v[sz], indices[sz]; // v[i] is value of i, indices[i] is node i is at what index in e
vector<int> adj[sz];
vector<euler> e={{0, 0}};
 
namespace BIT{ // of the values
       int bit[sz];
       void update(int pos, int val){
              for(; pos<sz; pos+=pos&-pos)
                     bit[pos]+=val;
       }
       int getsum(int x, int sum=0){
              for(; x>0; x-=x&-x) sum+=bit[x];
              return sum;
       }
       int sum(int a, int b){
              return(getsum(b)-getsum(a-1));
       }
} using namespace BIT;
 
 
void dfs(int node, int par=0){
       int start=time++;
       for(int i:adj[node]) if(i!=par) dfs(i, node);
       e.push_back({node, time-start});
       indices[node]=e.size()-1;
       update(e.size()-1, v[node]);
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
 
	for(int i=1; i<=n; i++) cin>>v[i];
 
       for(int i=0; i<n-1; i++){
              int a,b; cin>>a>>b;
              adj[a].emplace_back(b);
              adj[b].emplace_back(a);
       }
 
       dfs(1);
 
       while(q--){
              int type, s; cin>>type>>s;
              if(type==1){
                     int x; cin>>x;
                     update(indices[s], x-v[s]);
                     v[s]=x;
              }
              else cout<<sum(indices[s]-e[indices[s]].size+1, indices[s])<<endl;
       }
}
