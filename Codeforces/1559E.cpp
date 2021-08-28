#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 2e5 + 5, mod = 998244353;
int n, m, nfl[sz], l[50], r[50];

void sieve(){ // look at parity
	for (int i = 1; i < sz; i++){
		for (int j = i; j < sz; j += i){
			nfl[j]++;
		}
	}
	//for (int i = 1; i < sz; i++) nfl[i] = (nfl[i] == 2 ? -1 : 1);
}

int compute(int x){
	vector<vector<int>> dp(n, vector<int>(4 * m / x + 3, 0)); // dp[i][j] is how many ways to make sum j*x with first i elements

	auto getl = [&](int a){ // return i where xi >= a
		for (int i = 0;; i++)
			if (x * i >= a) return i;
	};
	auto getr = [&](int a){
		for (int i = 0;; i++)
			if (x * i > a) return i - 1;
	};
	auto psum = [&](int pos){
		for (int i = 1; i < 4 * m / x + 3; i++)
			dp[pos][i] = (dp[pos][i] + dp[pos][i - 1]) % mod;
	};
	auto disp = [&](){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 2 * m / x + 3; j++){
				cout << dp[i][j] << " ";
			}cout << endl;
		}
	};
	dp[0][getl(l[0])]++;
	dp[0][getr(r[0]) + 1]--;
	//cout << "size is " << n + 1 << " by " << 2 * m / x + 3 << endl;
	for (int pos = 0; pos < n - 1; pos++){
		//cout << "at pos = " << pos << endl;
		psum(pos);
		int mn = getl(l[pos + 1]), mx = getr(r[pos + 1]);
		if (mn > mx) continue;
		for (int cur = 0; cur < m / x + 1; cur++){ // current sum
			if (!dp[pos][cur]) continue;
			//cout << "at current sum = " << cur << " scaled add candidate = " << cur * x << endl;
			//cout << "dp[" << pos + 1 << "][" << cur + mn << "]++" << endl;
			//cout << "dp[" << pos + 1 << "][" << cur + mx + 1 << "]--" << endl;
			int configs = dp[pos][cur];
			int& f = dp.at(pos + 1).at(cur + mn);
			int& s = dp.at(pos + 1).at(cur + mx + 1);
			f = (f + mod + configs) % mod;
			s = (s + mod - configs) % mod;

		}
	//	cout << "after finishing it: " << endl;
		//disp();
	}
	psum(n - 1);
	int tmp = 0;
	// sum leq m
	for (int i = 0; i <= m / x; i++)
		tmp = (tmp + dp[n - 1][i]) % mod;

	//cout << "final disp " << endl;
	//disp();
	return tmp;
}

int compute2(int x){
	vector<vector<int>> dp(n, vector<int>(4 * m / x + 3, 0)); // dp[i][j] is how many ways to make sum j*x with first i elements

	auto getl = [&](int a){ // return i where xi >= a
		for (int i = 0;; i++)
			if (x * i >= a) return i;
	};
	auto getr = [&](int a){
		for (int i = 0;; i++)
			if (x * i > a) return i - 1;
	};
	auto psum = [&](int pos){
		for (int i = 1; i < 4 * m / x + 3; i++)
			dp[pos][i] = (dp[pos][i] + dp[pos][i - 1]) % mod;
	};
	auto disp = [&](){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 2 * m / x + 3; j++){
				cout << dp[i][j] << " ";
			}cout << endl;
		}
	};
	dp[0][getl(l[0])]++;
	dp[0][getr(r[0]) + 1]--;
	cout << "size is " << n + 1 << " by " << 2 * m / x + 3 << endl;
	for (int pos = 0; pos < n - 1; pos++){
		cout << "at pos = " << pos << endl;
		psum(pos);
		int mn = getl(l[pos + 1]), mx = getr(r[pos + 1]);
		if (mn > mx) continue;
		cout << "mn, mx to add: " << mn << " " << mx << endl;
		for (int cur = 0; cur < m / x + 1; cur++){ // current sum
			if (!dp[pos][cur]) continue;
			cout << "at current sum = " << cur << " scaled  = " << cur * x << endl;
			cout << "dp[" << pos + 1 << "][" << cur + mn << "]++" << endl;
			cout << "dp[" << pos + 1 << "][" << cur + mx + 1 << "]--" << endl;
			int configs = dp[pos][cur];
			int& f = dp.at(pos + 1).at(cur + mn);
			int& s = dp.at(pos + 1).at(cur + mx + 1);
			f = (f + mod + configs) % mod;
			s = (s + mod - configs) % mod;

		}
		cout << "after finishing it: " << endl;
		disp();
	}
	psum(n - 1);
	int tmp = 0;
	// sum leq m
	for (int i = 0; i <= m / x; i++)
		tmp = (tmp + dp[n - 1][i]) % mod;

	cout << "final disp " << endl;
	disp();
	return tmp;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
	}
	sieve();
	for (int i = 1; i <= 20; i++){
		cout << "nfl[" << i << "] = " << nfl[i] << endl;
	}

	int ans = compute(1);
	for (int i = 2; i <= m; i++){
		int c = compute(i);
		if (i * 2 <= m){
			ans = (ans - c + mod) % mod;
		}
		else{
			ans = (ans + (nfl[i] - 3) * c) % mod;
		}
		/*
		if (i == 2){
			int add = 0;
			cout << "i = " << i << ": " << (add=compute2(i)) << endl;
			ans = (ans + add * nfl[i] + mod) % mod;
		}
		else{
			//cout << "i = " << i << ": " << compute(i) << endl;
			ans = (ans + compute(i) * nfl[i] + mod) % mod;
		}
*/
	}
	cout << ans << endl;
}
