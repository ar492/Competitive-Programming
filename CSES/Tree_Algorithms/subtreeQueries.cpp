/*

flip the table

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
       int getsum(int x, int sum=0){ for(; x>0; x-=x&-x) sum+=bit[x]; return sum; }
       int sum(int a, int b){ return(getsum(b)-getsum(a-1)); }
       void add(int x, int val){ for(; x<sz; x+=x&-x) bit[x]+=val; }
       void change(int x, int val){ add(x, val-(getsum(x)-getsum(x-1))); }
}using namespace BIT;

void dfs(int node, int par=0){
       int start=time++;
       for(int i:adj[node]) if(i!=par) dfs(i, node);
       e.push_back({node, time-start}); // storing subtree sizes for nodes in dfs order
       indices[node]=e.size()-1;
       add(e.size()-1, v[node]);
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
                     change(indices[s], x);
                     v[s]=x;
              }
              else cout<<sum(indices[s]-e[indices[s]].size+1, indices[s])<<endl;
       }
}
