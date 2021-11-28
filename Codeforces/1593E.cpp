#include<bits/stdc++.h>
using namespace std;
#define sz(i) (int)((i).size())

const int sz = 4e5 + 5;
set < int > adj[sz];
int turn[sz];
const int inf = 2e9;

signed main(){
	cin.tie(0) -> sync_with_stdio(0);

	fill(turn, turn + sz, inf);
	int t; cin >> t;
	while(t -- ){
		int n, k; cin >> n >> k;

		for(int i = 0; i < n - 1; i ++ ){
			int u, v; cin >> u >> v;
			adj[u].insert(v); adj[v].insert(u);
		}
		if(n == 1) cout << 0 << endl;
		else{
			queue < int > q;
			for(int i = 1; i <= n; i ++ ){
				if(sz(adj[i]) == 1){
					q.push(i);
					turn[i] = 0;
				}
			}

			while( ! q.empty()){
				int u = q.front();
				q.pop();
				for(int i : adj[u]){
					adj[i].erase(u);
					if(sz(adj[i]) == 1){
						turn[i] = turn[u] + 1;
						q.push(i);
					}
				}
			}
			int ans = 0;
			for(int i = 1; i <= n; i ++ ){
				ans += (turn[i] >= k);
			}
			cout << ans << endl;
		}
		for(int i = 1; i <= n; i ++ ){
			turn[i] = inf;
			adj[i].clear();
		}
	}
}

