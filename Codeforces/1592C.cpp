#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 1e5 + 5;
vector<int> adj[sz];
int n, a[sz], xors[sz], x, cnt, k;

void dfs(int node, int par = -1){
	xors[node] = a[node];
	for (int i : adj[node]){
		if (i == par) continue;
		dfs(i, node);
		if (xors[i] == x) cnt++;
		else xors[node] ^= xors[i];
	}
	if (node != 1) return;
	cout << (cnt >= 2 && k - 1 >= 2 ? "yes" : "no") << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			x ^= a[i];
		}
		for (int i = 0; i < n - 1; i++){
			int u, v; cin >> u >> v;
			adj[u].push_back(v); adj[v].push_back(u);
		}
		if (!x) cout << "yes" << endl;
		else dfs(1);

		for (int i = 1; i <= n; i++){
			adj[i].clear();
			xors[i] = 0;
		}
		x = cnt = 0;
	}
}

