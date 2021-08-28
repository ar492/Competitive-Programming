/*
 * using small to large merging
*/


#include<bits/stdc++.h>
using namespace std;

const int sz = 2e5 + 5;
vector<int> adj[sz];
int n, ans[sz];
set<int> colors[sz];

void dfs(int node, int par = -1){
	for (int i : adj[node]){
		if (i != par){
			dfs(i, node);
			if (colors[i].size() > colors[node].size()){
				colors[i].swap(colors[node]);
			}
			for (int j : colors[i]){
				colors[node].insert(j);
			}
		}
	}
	ans[node] = colors[node].size();
}

signed main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		int u; cin >> u; colors[i].insert(u);
	}
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
}
