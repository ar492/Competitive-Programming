// https://cses.fi/problemset/task/1138

#ifdef LOCAL
       #include "C:\\Users\\gbpol\\Desktop\\Useful\\cp.h"
#else
       #include <bits/stdc++.h>
#endif
 
#define int long long
using namespace std;
#define time timee
 
struct euler{ int node, size, pathsum; };
 
const int sz=2e5+2;
vector<int> adj[sz];
vector<euler> tree={{0, 0, 0}}; // flattened 1-indexed tree using euler tour technique
int n,q, vals[sz], time, ind[sz]; // ind[i] is what index of euler table is node i
 
namespace BIT{ // of "tree"
       int bit[sz];
       int psum(int x, int sum=0){ for(; x>0; x-=x&-x) sum+=bit[x]; return sum; }
       int sum(int a, int b){ return(psum(b)-psum(a-1)); } // inclusive
       void add(int x, int val){ for(; x<sz; x+=x&-x) bit[x]+=val; }
       void change(int x, int val){ add(x, val-(psum(x)-psum(x-1))); }
}using namespace BIT;
 
void dfs(int node, int par=0, int pathsum=0){
       pathsum+=vals[node];
       int start=time++;
       tree.push_back({node, -1, pathsum});
       ind[node]=tree.size()-1;
       add(ind[node], pathsum-tree[ind[node]-1].pathsum); // range update point sum (this is standard .. the BIT is interpreted as a prefix)
       // a[3] = bit[1]+bit[2]+bit[3]
       for(int i:adj[node]) if(i!=par) dfs(i, node, pathsum);
       tree[ind[node]].size=time-start;
}
 
signed main(){
       cin.tie(0)->sync_with_stdio(0);
       cin>>n>>q;
 
       for(int i=1; i<=n; i++) cin>>vals[i];
       for(int i=1; i<=n-1; i++){
              int a,b; cin>>a>>b;
              adj[a].push_back(b); adj[b].push_back(a);
       }
       dfs(1);
       while(q--){
              int type, s; cin>>type>>s;
              if(type==2) cout<<psum(ind[s])<<endl;
              else{
                     int x; cin>>x;
                     int deltapath=(x-vals[s]); // how much the value of the path from s to 1 changes
                     vals[s]=x;
                     add(ind[s], deltapath); add(ind[s]+tree[ind[s]].size, -deltapath);
 
              }
       }
}
