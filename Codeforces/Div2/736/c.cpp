/* 
	author: ar492 
	created: 08/01/2021 at 11:50:03
*/

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 2e5 + 5;
set<int> adj[sz];
set<int> g[sz];

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int ans = 0;
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		g[u].insert(v);
		adj[u].insert(v); adj[v].insert(u);
	}
	for (int i = 1; i <= n; i++) if (!sz(g[i])) ans++;
	
	int q; cin >> q;
	while (q--){
		int type; cin >> type;
		if (type == 3){
			cout << ans << endl;
		}
		else{
			int u, v; cin >> u >> v;
			if (type == 1){
				if (v < u) swap(u, v); // v>u
				if (!sz(g[u])) ans--; // u was a root, not anymore. so sub 1
				adj[v].insert(u); adj[u].insert(v); g[u].insert(v);
			}
			else{
				if (v < u) swap(u, v); // v>u
				adj[u].erase(v); adj[v].erase(u); g[u].erase(v);
				ans += (!sz(g[u])); // u is a new root
			}
		}
	}
}


/*

10 9
10 8
8 2
2 3
8 9
9 4
9 6
6 5
6 7
7 1
12
3
2 8 10
3
1 8 10
3
1 10 9
3
2 10 9
2 8 10
2 8 9
2 8 2
3
*/

/*

output

4
3
4
3
3


2 0
5
3
1 1 2
3
2 1 2
3

*/