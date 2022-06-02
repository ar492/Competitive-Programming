#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int mod = 998244353;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		int n, m, k, q; cin >> n >> m >> k >> q;
		map<int, int> rows, cols;
		vector<array<int, 2>> queries;
		for (int i = 0; i < q; i++){
			int u, v; cin >> u >> v;
			queries.pb({ u, v });
		}
		reverse(all(queries));
		int ans = 1;
		for (auto x : queries){
			if (rows.count(x[0]) and cols.count(x[1])) continue;
			if (sz(rows) == n or sz(cols) == m) continue;
			ans = (ans * k) % mod;
			rows[x[0]]++; cols[x[1]]++;
		}
		cout << ans << endl;
	}
	
}
