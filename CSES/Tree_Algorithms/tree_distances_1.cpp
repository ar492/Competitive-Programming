// author: ar492
// created: 2022-01-10 21:47:08

// easier way is to use diameter

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define nl "\n"
using namespace std;

const int sz = 2e5 + 1;
int n, up[sz], down[sz]; // up is max length of path going up. down is max length of path going down
vector<int> adj[sz];

void dfs(int node, int par = -1){
	for (int i : adj[node]){
		if (i != par){
			dfs(i, node);
			down[node] = max(down[node], down[i] + 1);
		}
	}
}

void dfs2(int node, int par = -1){
	map<int, int> downs; // to fill ups for the kids
	if (par != -1) up[node] = max(up[node], up[par] + 1);
	for (int i : adj[node]) if (i != par) downs[down[i]]++;
	for (int i : adj[node]){
		if (i == par) continue;
		downs[down[i]]--;
		if (downs[down[i]] == 0) downs.erase(down[i]);
		up[i] = max(up[i], sz(downs) ? downs.rbegin()->first + 2 : 0);
		downs[down[i]]++;
		dfs2(i, node);
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].eb(v); adj[v].eb(u);
	}
	dfs(1);
	dfs2(1);
	for (int i = 1; i <= n; i++)
		cout << max(up[i], down[i]) << nl;
}
