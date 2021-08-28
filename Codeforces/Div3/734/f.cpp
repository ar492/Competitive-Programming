

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)(X.size())

const int mod = 1e9 + 7;

const int maxn = 105;
int C[maxn + 1][maxn + 1];

void setup(){
	C[0][0] = 1;
	for (int n = 1; n <= maxn; ++n){
		C[n][0] = C[n][n] = 1;
		for (int k = 1; k < n; ++k)
			C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;
	}
}

signed main(){
	setup();
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		int ans = 0;
		vector<int> adj[n + 1];
		for (int i = 0; i < n - 1; i++){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if (k == 2){
			cout << ((n * (n - 1)) / 2) % mod << endl;
			continue;
		}
		for (int i = 1; i <= n; i++){
			cout << "bfs from " << i << endl;
			queue<int> q;
			vector<int> vis(n + 1);
			vis[i] = true;
			vector<int> dist(n + 1);
			q.push(i);
			while (!q.empty()){
				int top = q.front();
				q.pop();
				for (int j : adj[top]){
					if (!vis[j]){
						vis[j] = 1;
						q.push(j);
						dist[j] = dist[top] + 1;
					}
				}
			}
			sort(all(dist));
			for (int j = 1; j < n; j++){
				int cnt = count(dist.begin(), dist.end(), j);
				ans = (ans + C[cnt][k]) % mod;
			}

			/*
			int cnt=0;
			for(int j=1; j<=n; j++){
				if(cnt==0) cnt++;
				if(j==n || dist[j]!=dist[j+1]){
					if(cnt>=k){
						ans=(ans+C[cnt][k])%mod;
					}
					cnt=0;
				}
				else if(dist[j]==dist[j+1]){
					cnt++;
				}
			}
			*/
		}
		cout << ans << endl;
	}
}

