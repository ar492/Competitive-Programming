#ifdef LOCAL
#include			<C:\\Users\\gbpol\\Desktop\\Useful\\cp.h>
#else
#include 			<bits/extc++.h> // stdc++
#endif
#define 			int long long
#define 			_ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
using namespace std;

const int sz=1e5+5, mod=1e9+7;
int n, k;
vector<int> adj[sz];
int dp[sz][4]; // dp[i][j] = number of ways to paint subtree of node i if i's color is j

void dfs(int node, int par=0){
       for(int i:adj[node]){
              if(i==par) continue;
              dfs(i, node);
              for(int color:{1, 2, 3}){
                     int sum=0;
                     for(int other:{1, 2, 3}) if(other!=color) sum=(sum+dp[i][other])%mod;
                     dp[node][color]=(dp[node][color]*sum)%mod;
              }
       }
}


signed main(){_
       ifstream cin("barnpainting.in"); ofstream cout("barnpainting.out");
       cin>>n>>k;
       for(int i=1; i<n; i++){
              int u,v; cin>>u>>v;
              adj[u].push_back(v); adj[v].push_back(u);
       }
       for(int i=0; i<sz; i++) fill(dp[i], dp[i]+4, 1);
       while(k--){
              int u, c; cin>>u>>c;
              for(int i=0; i<4; i++) if(i!=c) dp[u][i]=0;
       }
       dfs(1);
       cout<<(dp[1][1]+dp[1][2]+dp[1][3])%mod<<endl;
}
