#include<bits/stdc++.h>
using namespace std;
#define int long long

const int sz=2e5+5;
int n, k, f[sz], ans;
vector<int> adj[sz];
bool is_uni[sz];

void dfs(int node, int par=0){
	f[node]=is_uni[node];
	for(int i:adj[node]){
		if(i!=par){
			dfs(i, node);
			f[node]+=f[i];
		}
	}
}

signed main(){
	cin>>n>>k;
	for(int i=0; i<2*k; i++){
		int u; cin>>u;
		is_uni[u]=true;
	}
	for(int i=0; i<n-1; i++){
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(int i=1; i<=n; i++){
		cout<<"f["<<i<<"] = "<<f[i]<<endl;
	}
	for(int i=2; i<=n; i++){
		ans+=min(f[i], 2*k-f[i]);
	}
	cout<<ans<<endl;
}
