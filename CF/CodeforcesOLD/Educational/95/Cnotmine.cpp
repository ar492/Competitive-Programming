#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define LL long long
#define st first
#define nd second
#define endl '\n'
using namespace std;

int main() {
	ifstream cin("input.in");
    ofstream cout("ooutput1.out");
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int dp[n + 3][2];
		int a[n + 2];
		a[n + 1] = 0;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		memset(dp, 0, sizeof dp);
		for(int i = n; i >= 1; --i)
			for(int j = 0; j < 2; ++j) {
				dp[i][j] = dp[i + 1][j ^ 1] + (j && (a[i] == j));
				dp[i][j] = min(dp[i][j], dp[i + 2][j ^ 1] + (j && (a[i] == j)) + (j && (a[i + 1] == j)));
			}
		cout << dp[1][1] << endl;
	}

}
