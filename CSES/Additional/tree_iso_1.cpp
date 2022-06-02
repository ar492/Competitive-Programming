// author: ar492
// created: 2022-02-11 18:15:28
// instead, sort path lexicographically
// then find dfs order of adj and compare

// observations: no way to find unique lexicographical order of a tree

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
	vector<vector<int>> adj;

	string dfs(int node, int par = -1){
		
	}
	tree(int& n){
		adj.resize(n + 1);
		for (int i = 0; i < n - 1; i++){
			int u, v; cin >> u >> v;
			adj[u].eb(v), adj[v].eb(u);
		}
		dfs(1);
	}
};

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		//cout << "n is " << n << endl;
		tree a(n), b(n);
		

	}
}

/*

1
7
7 1
1 2
4 3
5 4
2 4
2 6
3 1
4 5
6 3
2 1
7 5
3 5

1
8
5 1
5 6
1 8
3 5
8 4
2 5
1 7
5 6
2 8
8 1
1 5
8 4
8 7
3 1
*/