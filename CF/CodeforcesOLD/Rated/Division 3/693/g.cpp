#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF=1e18, sz=2e5+1;
int t,n,m;
vector<int> adj[sz];
bool v[sz];
int dist[sz], dp[sz];

void setup(){
     for(int i=1; i<=n; i++){
          adj[i].clear();
          dist[i]=dp[i]=INF;
          v[i]=0;
     }
     dist[1]=dp[1]=0;
     while(m--){
          int u,v; cin>>u>>v;
          adj[u].push_back(v);
     }
     queue<int> q;
     q.push(1);
     while(!q.empty()){
          int node=q.front(); q.pop();
          for(auto i:adj[node]){
               if(dist[i]==INF){
                    dist[i]=dist[node]+1;
                    q.push(i);
               }
          }
     }
}

void dfs(int node){
     v[node]=1; dp[node]=dist[node];
     for(auto i:adj[node]){
          if(!v[i] && dist[node]<dist[i]) dfs(i);
          if (dist[node] < dist[i]) dp[node] = min(dp[node], dp[i]);
          else dp[node] = min(dp[node], dist[i]);
     }
}

signed main(){
     cin>>t;
     while(t--){
          cin>>n>>m;
          setup();
          dfs(1);
          for(int i=1; i<=n; i++) cout<<dp[i]<<" "; cout<<endl;
     }
     return 0;
}
