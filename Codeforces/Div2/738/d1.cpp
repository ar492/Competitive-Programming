#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 2e5 + 5;
int n, m1, m2;
vector<int> adj[sz];

struct dsu{
	int parent[sz], size[sz];
	dsu(){
		for (int i = 0; i < n; i++){
			parent[i] = i; size[i] = 1;
		}
	}
	int rep(int v){
		if (v == parent[v]) return v;
		return parent[v] = rep(parent[v]);
	}
	void unite(int a, int b){
		a = rep(a); b = rep(b);
		if (a != b){
			if (size[a] < size[b]) swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
};


signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	cin >> n >> m1 >> m2;
	dsu mocha, diana;
	
	while (m1--){
		int u, v; cin >> u >> v;
		mocha.unite(u, v);
	}
	while (m2--){
		int u, v; cin >> u >> v;
		diana.unite(u, v);
	}
	vector<array<int, 2>> edges;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (mocha.rep(i) != mocha.rep(j) && diana.rep(i) != diana.rep(j)){
				edges.push_back({ i, j });
				mocha.unite(i, j);
				diana.unite(i, j);
			}
		}
	}
	cout << sz(edges) << endl;
	for (auto i : edges){
		cout << i[0] << " " << i[1] << endl;
	}
}
