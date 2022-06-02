#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

set<set<int>> press;
const int mod = 1e9 + 7;

void pre(){
	for (int i = 1; i <= 9; i++){
		press.insert({ i });
	}
	for (int i = 1; i <= 8; i++){
		press.insert({ i, i + 1 });
	}
	for (int i = 1; i <= 3; i++){
		press.insert({ i, i + 3 });
		press.insert({ i + 3, i + 6 });
	}
	press.insert({ 1, 2, 4, 5 });
	press.insert({ 2, 3, 5, 6 });
	press.insert({ 4, 5, 7, 8 });
	press.insert({ 5, 6, 8, 9 });
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	pre();
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int n = len(s);
		vector<int> v;
		for (char i : s) v.eb(i - '0');
		vector<vector<int>> dp(3, vector<int>(n, 0)); // dp[0][i] = numways for v[i] = v[i]. dp[1][i] = numways for mistake at (i-1, i). dp[2][i] = numways for mistake len 4, not included in any others
		vector<int> can2(n); // 1 if can make 2 end at i, 2 if can make 4 end at i
		dp[0][0] = 1;
		for (int i = 1; i < n; i++){
			
			
		}
		cout << dp[n - 1] << endl;
	}
}
