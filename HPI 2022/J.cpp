#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int maxn = 1e5, maxe = 40;

vector<int> adj[maxn];
bool vis[maxn];
int depth[maxn];
int up[maxn][maxe];

void dfs(int node, int p, int d){
	up[node][0] = p, vis[node] = 1, depth[node] = d;
	for (int i : adj[node])
		if (!vis[i])
			dfs(i, node, d + 1);
}

int lift(int node, int k){
	if (k == 0) return node;
	int gp2 = log2(k);
	if (up[node][gp2] == -1) return -1;
	return(lift(up[node][gp2], k - (1 << gp2)));
}

int lca(int a, int b){
	a = lift(a, depth[a] - min(depth[a], depth[b]));
	b = lift(b, depth[b] - min(depth[a], depth[b]));
	if (a == b) return a;
	for (int l = maxe - 1; l >= 0; --l)
		if (up[a][l] != up[b][l]) a = up[a][l], b = up[b][l];
	return up[a][0]; //parent of a
}

int works[maxn];


signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int n, q; cin >> n >> q;
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	

}
