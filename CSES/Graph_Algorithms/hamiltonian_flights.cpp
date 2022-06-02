#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
//#define int long long
#define nl "\n"
using namespace std;
 
int n, m;
vector<int> adj[20];
int dp[1 << 20][20]; // mask, current city
const int mod = 1e9 + 7;
 
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
	}
	dp[1][0] = 1;
	for (int mask = 1; mask < (1 << n) - 1; mask++) // O(2^n * (n+2m)) / const from next line + others
		if ((mask & (1 << (n - 1))) == 0)// if last city is not already visited
			for (int i = 0; i < n; i++) // current city candidate
				if ((mask & (1 << i))) // if its a valid candidate
					for (int j : adj[i]) // next city candidates
						if ((mask & (1 << j)) == 0) // if its a valid canaidate
							dp[mask | (1 << j)][j] = (dp[mask | (1 << j)][j] + dp[mask][i]) % mod;
	cout << dp[(1 << n) - 1][n - 1] << endl;
}