#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, ans;
const int sz = 2e5 + 5;
int sizes[sz], dp[sz];
vector<int> adj[sz];

void dfs(int node, int par = 0){
	sizes[node] = 1;
	for (int i : adj[node]){
		if (i != par){
			dfs(i, node);
			sizes[node] += sizes[i];
		}
	}
}

void pull(int node, int par = 0){
	if (par != 0) dp[node] = dp[par] + n - 2 * sizes[node];
	ans = max(ans, dp[node]);
	for (int i : adj[node]) if (i != par) pull(i, node);
}

signed main(){
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	int root;
	for (int i = 1; i <= n; i++){
		if ((int)(adj[i].size()) == 1){
			dfs(root = i); break;
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += sizes[i];
	dp[root] = ans = sum;
	pull(root);
	cout << ans << endl;
}