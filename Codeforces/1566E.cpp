#include<bits/stdc++.h>
using namespace std;
#define sz(X) ((int)(X).size())
#define int long long

const int sz = 2e5 + 5;
vector < int > adj[sz];
bool good[sz];
int ans;

void dfs(int node, int par = 0){
	// if child is a leaf or at least one child is not good, current node is good
	for(int i : adj[node]){
		if(i == par) continue;
		dfs(i, node);
		if(node == 1) continue;
		if(sz(adj[i]) == 1){ // i is leaf
			good[node] = 1;
			continue;
		}
		if(good[i] == 0) good[node] = 1;
	}
	if(sz(adj[node]) > 1){
		bool full = 1;
		for(int i : adj[node]){
			if(i == par) continue;
			full &= good[i];
			ans -= good[i];
		}
		ans += full;
	}
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t; cin >> t;
	while(t -- ){
		int n; cin >> n;
		for(int i = 0; i < n - 1; i ++ ){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for(int i = 2; i <= n; i ++ )
			ans += (sz(adj[i]) == 1);
		dfs(1);
		cout << ans << endl;
		for(int i = 1; i <= n; i ++ ){
			adj[i].clear();
			good[i] = 0;
		}
		ans = 0;
	}
}
