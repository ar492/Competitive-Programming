// std::assign is horrendously slow

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>

string n;
int k, len, dp[10][1024][2], realans[10];
bool done;

bool dfs(int pos, int mask, bool tight){ // tight means for all i < pos, all nb[i] <= n[i]
	if (__builtin_popcount(mask) > k || done) return false;
	if (pos == len) return true;
	if (dp[pos][mask][tight] != -1) return dp[pos][mask][tight];
	bool ans = 0;
	int low = tight ? n[pos] - '0' : 0;
	for (int i = low; i < 10; i++){
		if (dfs(pos + 1, mask | (1 << i), tight & (i == low))){
			ans = done = 1;
			realans[pos] = min(realans[pos], i);
			return dp[pos][mask][tight] = ans;
		}
	}
	return dp[pos][mask][tight] = ans;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--){
		for (int i = 0; i < 10; i++){
			realans[i] = 69;
			for (int j = 0; j < 1024; j++) dp[i][j][0] = dp[i][j][1] = -1;
		}
		done = 0;
		cin >> n >> k;
		len = n.length();
		dfs(0, 0, 1);
		for (int i = 0; i < len; i++){
			cout << realans[i];
		}cout << endl;
	}
}
