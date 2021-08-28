#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 4e5+5;
const int mod = 998244353;
int nf[sz]; // nd = number of divisors
int n, m, ans;
array<int, 2> ranges[sz];

void sieve(){
	for (int i = 1; i < sz; i++)
		for (int j = i; j < sz; j += i)
			nf[j]++;
	nf[1] = 2;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	sieve();
	for (int i = 1; i <= 16; i++){
		//cout << i << " has " << nf[i] << " factors " << endl;
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> ranges[i][0] >> ranges[i][1];

	vector<vector<int>> dp(55, vector<int>(2*m + 5));
	auto psum = [&](int k, int i){
		for (int j = i; j <= m; j+=i){
			dp[k][j] = (dp[k][j] + dp[k][j-i] + mod) % mod;
		}
	};
	auto in = [&](int val, int pos){
		return val >= ranges[pos][0] && val <= ranges[pos][1];
	};
	
	for (int i = 1; i <= m; i++){ // O(m)
		//if (!prime[i]) continue;
		dp.assign(55, vector<int>(2 * m + 5, 0));
		for (int k = 1; k <= n; k++){ // O(nlogm)
			if (k == 1){ // base
				for (int j = ranges[1][0]; j <= ranges[1][1]; j++){
					if (j % i) continue;
					dp[1][j] = 1;
				}
			}
			if (k == n) continue;
			int mn = (ranges[k + 1][0] / i) * i;
			int mx = (ranges[k + 1][1] / i) * i;
			if (mn * i < ranges[k + 1][0]) continue;
			for (int j = mn; j <= m; j += i){
				int cur = dp[k][j];
				if (!cur) continue;
				dp[k + 1][j + mn] = (dp[k + 1][j + mn] + cur) % mod;
				dp[k + 1][j + mx + 1] = (dp[k + 1][j + mx + 1] - cur + mod) % mod;
			}
			psum(k + 1, i);
		}
		int tmp = 0;
		for (int j = i; j <= m; j += i){ // sum is multiple of i
			tmp = (tmp + dp[n][j]) % mod;
		}
		if (nf[i] == 2){
			ans = (ans + tmp) % mod;
		}
		else{
			ans = (ans - (nf[i] - 2) * tmp + 100 * mod) % mod;
		}
		if (i == 1){
			cout << "total ans is " << tmp << endl;
		}
	}
	cout << ans << endl;
}