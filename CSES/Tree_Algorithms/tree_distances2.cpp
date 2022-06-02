#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 2e5 + 5;
vector<int> adj[sz];
int n, dp[sz], sizes[sz];

void dfs1(int node, int par = -1, int dist = 0){ // find sizes and dp[1]
	sizes[node] = 1;
	dp[1] += dist;
	for (int i : adj[node]){
		if (i == par) continue;
		dfs1(i, node, dist + 1);
		sizes[node] += sizes[i];
	}
}

void dfs2(int node, int par = -1){
	for (int i : adj[node]){
		if (i == par) continue;
		dp[i] = dp[node] + n - 2 * sizes[i];
		dfs2(i, node);
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1);
	dfs2(1);
	for (int i = 1; i <= n; i++){
		cout << dp[i] << (i == n ? "\n" : " ");
	}
}
