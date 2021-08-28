#include<bits/stdc++.h>
using namespace std;
#define int long long

const int sz = 2e5;
const int mod = 998244353;
int sizes[sz], depths[sz], n, q;
int fact[sz];

void dfs(int node, int par = 0, int d=0){
	sizes[node] = 1;
	depths[node] = d;
	for (int i : adj[node]){
		if (i != par){
			dfs(i, node, d+1);
			sizes[node] += sizes[i];
		}
	}
}

int expo(int a, int b){
	if (a == 0) return b == 0;
	int ans = 1;
	while(b){
		if (b & 1) ans = (ans * a) % mod;
		b >>= 1LL;
		a = (a * a) % mod;
	}
	return ans;
}

signed main(){
	cin >> n >> q;
	fact[0] = 1;
	for (int i = 1; i <= 500; i++){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while (q--){
		int u, v, k; cin >> u >> v >> k;
		if (depths[u] > depths[v]) swap(u, v);
		int in_u, out_u, in_v, out_v;
		in_u = sizes[u] - 1; // not including u
		in_v = n - (sizes[v]);
		int ans = (in_u * in_v) % mod;

	}
}