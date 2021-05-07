#ifdef LOCAL
#include			<C:\\Users\\gbpol\\Desktop\\Useful\\cp.h>
#else
#include 			<bits/extc++.h> // stdc++
#endif
#define 			int long long
#define 			_ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
using namespace std;

const int sz=3e5;
int n, m;
vector<int> adj[sz];
int vis[sz];
deque<int> topo;
bool possible=0;

void dfs(int node, int start){
       vis[node]=1;
       for(int i:adj[node]){
              if(i==start) cout<<"IMPOSSIBLE"<<endl, exit(0);
              if(vis[i]) continue;
              dfs(i, start), vis[i]=2;
       }
       topo.push_front(node);
}

signed main(){_
       // check for indegree 0
       cin>>n>>m;
       for(int i=0; i<m; i++){
              int a,b; cin>>a>>b;
              adj[a].push_back(b);
       }

       for(int i=1; i<=n; i++) if(!vis[i]) dfs(i, i);
       for(int i=1; i<=n; i++) if(vis[i]==1) possible=true;

       if(possible) for(int i=0; i<n; i++) cout<<topo[i]<<(i==n-1 ? "\n" : " ");
       else cout<<"IMPOSSIBLE"<<endl;
}
