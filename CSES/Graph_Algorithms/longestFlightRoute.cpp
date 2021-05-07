#ifdef LOCAL
#include			<C:\\Users\\gbpol\\Desktop\\Useful\\cp.h>
#else
#include 			<bits/extc++.h> // stdc++
#endif
#define 			int long long
#define 			_ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
#define prev _prev
using namespace std;

const int sz=2e5+5;
vector<int> adj[sz];
bool vis[sz], possible;
deque<int> topo;
int n, m, cnt, indices[sz], dp[sz], prev[sz];

void dfs(int node){
       vis[node]=1;
       if(node==1 || node==n) cnt++;
       if(cnt==2) possible=1;
       for(int i:adj[node]) if(!vis[i]) dfs(i);
       topo.push_front(node);
}

signed main(){_
       cin>>n>>m;
       for(int i=0; i<m; i++){
              int a,b; cin>>a>>b; adj[a].push_back(b);
       }
       for(int i=1; i<=n; i++, cnt=0) if(!vis[i]) dfs(i);
       if(!possible) cout<<"IMPOSSIBLE"<<endl, exit(0);
       topo.push_front(0); // dummy for one indexing
       for(int i=1; i<=n; i++) indices[topo[i]]=i;
       for(int i=indices[1]; i<indices[n]; i++)
              for(int j:adj[topo[i]])
                     if(dp[topo[i]]+1>dp[j])
                            prev[j]=topo[i], dp[j]=(dp[topo[i]]+1);
       deque<int> path;
       int i=n;
       while(i) path.push_front(i), i=prev[i];
       cout<<dp[n]+1<<endl;
       for(int j=0; j<dp[n]+1; j++) cout<<path[j]<<(j==dp[n] ? "\n" : " ");


}


/*

10 10
3 9
6 5
6 9
2 8
4 8
1 2
7 10
7 6
7 5
8 10

3 3
1 3
1 3
2 3

3 2
1 3
2 3

*/
