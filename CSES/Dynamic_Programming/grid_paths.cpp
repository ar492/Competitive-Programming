#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int mod = 1e9 + 7;
const int sz = 1e3 + 5;
int dp[sz][sz];
char g[sz][sz];

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> g[i][j];
		}
	}
	if (g[0][0] != '*') dp[0][0] = 1;
	for (int i = 1; i < n; i++){
		if (g[i][0] != '*') dp[i][0] = dp[i - 1][0];
		if (g[0][i] != '*') dp[0][i] = dp[0][i - 1];
	}
	for (int i = 1; i < n; i++){
		for (int j = 1; j < n; j++){
			if (g[i][j] == '*') continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	cout << dp[n - 1][n - 1] << endl;
}
