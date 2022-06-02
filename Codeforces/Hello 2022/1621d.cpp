// author: ar492
// created: 2022-01-03 11:28:34
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int g[501][501], n;

int compute(vector<vector<int>>& c){ // left to bottom
	return min({ c[0][0], c[0].back(), c.back()[0], c.back().back() });
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < 2 * n; i++){
			for (int j = 0; j < 2 * n; j++){
				cin >> g[i][j];
			}
		}
		int ans = 0;
		for (int i = n; i < 2 * n; i++){
			for (int j = n; j < 2 * n; j++){
				ans += g[i][j];
			}
		}
		vector<vector<int>> g1(n, vector<int>(n));
		auto g2 = g1;
		for (int i = 0; i < n; i++){
			for (int j = n; j < 2 * n; j++){
				g1[i][j - n] = g[i][j];
				g2[i][j - n] = g[i + n][j - n];
			}
		}
		ans += min(compute(g1), compute(g2));
		cout << ans << endl;

	}
}
