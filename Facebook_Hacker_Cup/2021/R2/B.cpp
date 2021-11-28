#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 8e5 + 5;
vector < int > adj[sz];
vector < int > euler{ - 1};
vector < int > depths{ - 1};
int colors[sz], firsts[sz]; // first 

namespace lca{
	int sparse[2 * sz + 5][30], logs[2 * sz + 5];
	int f(int p1, int p2){ return min(p1, p2); }
	void build(){
		for (int i = 2; i <= 2*sz+1; i ++ ) logs[i] = logs[i / 2] + 1;
		for (int i = 1; i <= 2*sz+1; i ++ ) sparse[i][0] = depths[i];
		for (int dep = 1; dep < 30; dep ++ )
			for (int i = 1; i + (1 << dep - 1) <= 2*sz+1; i ++ )
				sparse[i][dep] = f(sparse[i][dep - 1], sparse[i + (1 << dep - 1)][dep - 1]);
	}
	int lca(int l, int r){
		l = firsts[l]; r = firsts[r];
		int lg = logs[r - l + 1];
		return(f(sparse[l][lg], sparse[r - (1 << lg) + 1][lg]));
	}
}
using namespace lca;

void dfs(int node, int par =- 1, int dep = 0){
	euler.push_back(node);
	depths.push_back(dep);
	for(int i : adj[node]){
		if(i == par) continue;
		dfs(i, node, dep + 1);
		euler.push_back(node);
		depths.push_back(dep);
	}
}

signed main(){
	int n; cin >> n;
	for(int i = 0; i < n - 1; i ++ ){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++ ){
		cin >> colors[i];
	}
	build();
	dfs(1);
	for(int i = 2 * n; i >= 0; i -- ){
		firsts[euler[i]] = i;
	}

}
