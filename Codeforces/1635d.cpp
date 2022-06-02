#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int mod = 1e9 + 7;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int n, p; cin >> n >> p; ++p;
	set<int> lft, rmv;
	for (int i = 0; i < n;i++){
		int u; cin >> u; lft.insert(u);
	}
	vector<int> dp(p);
	map<int, int> m;
	for (int i : lft){
		int o = i;
		while (i){
			if (i & 1) i /= 2;
			else if (i % 4 == 0) i /= 4;
			else break;
			if (lft.count(i)) rmv.insert(o);
		}
	}
	for (auto i : rmv) lft.erase(i);
	for (auto i : lft){
		int lst;
		for (int j = 0; j < 32; j++)
			if (i & (1ll << j)) // most sig bit
				lst = j;
		m[lst]++;
	}
	int ans = 0;
	for (int i = 0; i < p; i++){
		dp[i] = (i - 1 >= 0 ? dp[i - 1] : 0ll) + (i - 2 >= 0 ? dp[i - 2] : 0ll);
		dp[i] = (dp[i] + m[i - 1]) % mod;
		ans = (ans + dp[i]) % mod;
	}
	cout << ans << nl;
}