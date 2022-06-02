// author: ar492
// created: 2021-12-31 18:25:29

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int sz = 2e5 + 1;
int n, k, ans;
vector<int> adj[sz];
deque<int> d[sz]; // d[i][j] is how many depth j is there at subtree i

void merge(deque<int>& a, deque<int>& b){ // first parameter has the merged contents
	if (sz(a) < sz(b)) swap(a, b);
	for (int i = 0; i < sz(b); i++)
		if (not ((k - i) < 0 or (k - i) >= sz(a)))
			ans += (b[i] * a[k - i]);
	for (int i = 0; i < sz(b); i++) // merge
		a[i] += b[i];
}

void dfs(int node, int par = -1){
	d[node].push_front(1);
	for (int i : adj[node]){
		if (i == par) continue;
		dfs(i, node);
		d[i].push_front(0);
		merge(d[node], d[i]);
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].eb(v); adj[v].eb(u);
	}

	dfs(1);
	cout << ans << endl;
}
