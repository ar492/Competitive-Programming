#ifdef LOCAL
#include<C:\Users\gbpol\Desktop\Useful\Competitive-Programming\Util\cp.h>
#else
#include<bits/extc++.h>
#endif
#define priority_queue std::priority_queue
#define all(X) (X).begin(),(X).end()
#define nl "\n"
#define int long long
#define sz(X) ((int)(X.size()))
#define _ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
using namespace std;

int n, c; // number of items, weight capacity of knapsack
int weights[1002], values[1002];
//int dp[1001][100001];
int dp[2][100001];
signed main(){_
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> weights[i];
	for (int i = 1; i <= n; i++) cin >> values[i];
	
	for (int i = 1; i <= n; i++){
		int v = values[i], w = weights[i];
		for (int j = 0; j <= c; j++){
			dp[i][j]=dp[i-1][j];
			if(j>=w) dp[i][j] = max({ v, dp[i - 1][j - w] + v });
		}
	}
	cout<<dp[n][c]<<endl;
	

	/*
	for (int i = 1; i <= n; i++){
		int v = values[i], w = weights[i];
		for (int j = 0; j < w; j++) dp[1][j] = dp[0][j];
		for (int j = w; j <= c; j++){
			dp[1][j] = max({ v, dp[0][j], dp[0][j - w] + v });
		}
		for (int j = 0; j <= c; j++){
			dp[0][j] = dp[1][j];
			dp[1][j] = 0;
		}
	}
	
	cout << dp[0][c] << endl;
*/
}