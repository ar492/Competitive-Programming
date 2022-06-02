// author: ar492
// created: 2021-12-30 23:50:36
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 5e4 + 2;
vector<int> adj[sz];
int n, k, paths[sz][501], ans;  // paths has only endpoints

void dfs(int node, int par = -1){
	paths[node][0] = 1; 
	for (int child : adj[node]){
		if (child == par) continue;
		dfs(child, node);

		for (int j = 0; j < k; j++){
			ans += (paths[node][j] * paths[child][k - j - 1]);
		}

		for (int j = 1; j <= k; j++){
			paths[node][j] += paths[child][j - 1];
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	
	dfs(1);
	cout << ans << endl;
}