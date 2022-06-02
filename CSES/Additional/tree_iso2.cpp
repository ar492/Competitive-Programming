// author: ar492
// created: 2022-02-11 18:15:28
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
// #define int long long
#define nl "\n"
using namespace std;
 
const int sz = 1e5 + 1;
 
struct tree{
	vector<vector<int>> adj, q;
	inline void dfs(int node, int par = -1, int dep = 0){
		q[dep].eb(sz(adj[node]));
		
		for (int i : adj[node])
			if (i != par)
				dfs(i, node, dep + 1);
	}
	inline tree(int& n){
		adj.resize(n + 1);
		q.resize(n + 1);
		for (int i = 0; i < n - 1; i++){
			int u, v; cin >> u >> v;
			adj[u].eb(v), adj[v].eb(u);
		}
		dfs(1);
		for (int i = 0; i <= n; i++) sort(all(q[i]));
	}
};
 
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
 
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		//cout << "n is " << n << endl;
		tree a(n), b(n);
		bool ans = true;
 
		for (int i = 0; i <= n; i++){
			ans &= (a.q[i] == b.q[i]);
		}
		cout << (ans ? "YES" : "NO") << nl;
	}
}