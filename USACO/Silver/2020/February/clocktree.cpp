#include<bits/stdc++.h>
using namespace std;

const int sz=2501;
vector<int> adj[sz];
int clocks[sz], config[sz], n;

bool pos=false;

void resetConfig(){ for(int i=1; i<=n; i++) config[i]=clocks[i]; }

void dfs(int node, int par, bool root=false){
     int add=0;
     for(auto i:adj[node]){
          if(i==par) continue;
          dfs(i, node);
          add+=12-config[i];
     }
     config[node]+=add;
     if(config[node]%12==0) config[node]=12;
     if(config[node]%12) config[node]%=12;
     if(root){
          pos=(config[node]==12 || config[node]==1);
          resetConfig();
     }
}

int main(){
     ifstream cin("clocktree.in"); ofstream cout("clocktree.out");
     cin>>n;
     for(int i=1; i<=n; i++) cin>>clocks[i];
     resetConfig();
     for(int i=0; i<n-1; i++){
          int u,v; cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     int ans=0;
     for(int i=1; i<=n; i++){
          dfs(i, i, true);
          ans+=pos; pos=0;
     }
     cout<<ans<<endl;
     return 0;
}
