#include<bits/stdc++.h>
using namespace std;
#define int long long
#define smin(a,b) a = min(a,b)
const int inf = 1e15;

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t; cin >> t;
	while(t -- ){
		int n; cin >> n;
		vector < int > a(n + 1);
		int mx = 0;
		for(int i = 0; i < n; i ++ ){
			cin >> a[i];
			mx = max(mx, a[i]);
		}		
		// |pos| <= 2mx
		// start at mx
		// dp[i][j] is min dist from right mark, if first i segments have been placed, at (dist to left mark = j)
		vector < vector < int >> dp(n + 1, vector < int > (2 * mx + 1, inf));
		dp[0][0] = 0;
		for(int i = 0; i < n; i ++ ){
			for(int j = 0; j <= 2 * mx; j ++ ){
				if(dp[i][j] == inf) continue;
				if(j + a[i] <= 2 * mx)
				smin(dp[i + 1][j + a[i]], max(dp[i][j] - a[i], 0ll)); // place at right
				smin(dp[i + 1][max(0ll, j - a[i])], dp[i][j] + a[i]);
			}
		}
		int ans = inf;
		for(int j = 0; j <= 2 * mx; j ++ ){
			smin(ans, j + dp[n][j]);
		}
		cout << "answer is " << ans << endl;

		
	}
}
