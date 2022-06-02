#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

char g[1000][1000];
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	for (int _ = 1; _ <= t; _++){
		cout << "Case #" << _ << ": \n";
		int n, m; cin >> n >> m;
		n = 2 * n + 1, m = 2 * m + 1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (i % 2 == 0 and j % 2 == 0) g[i][j] = '+';
				else if (i % 2 == 0 and j & 1) g[i][j] = '-';
				else if (i & 1 and j & 1) g[i][j] = '.';
				else g[i][j] = '|';
			}
		}
		g[0][0] = g[0][1] = g[1][0] = '.';
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << g[i][j];
			}cout << endl;
		}
	}
}
