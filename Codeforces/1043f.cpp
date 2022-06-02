#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int sz = 3e5 + 5, inf = 1e18;
int a[sz], factors[sz];
array<int, 3> dp[2][sz]; // <# numbers, gcd, # factors of gcd>

void pre(){
	vector<int> primes(sz);
	for (int i = 2; i < sz; i++)
		if (primes[i] == 0)
			for (int j = i; j < sz; j += i)
				primes[j] = i;
	for (int i = 1; i < sz; i++){
		int j = i, ans = 1;
		while (j != 1){
			int div = primes[j], cnt = 0;
			while (j % div == 0) cnt++, j /= div;
			ans *= (cnt + 1);
		}
		factors[i] = ans;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	pre();
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[0][0] = { 0, 0, inf};
	dp[1][0] = { 1, a[0], factors[a[0]] };
	int ans = inf;
	for (int i = 1; i < n; i++){
		auto x = dp[0][i - 1], y = dp[1][i - 1];
		int f1 = factors[gcd(a[i], x[1])], f2 = factors[gcd(a[i], y[1])];
		if (f1 > f2) swap(x, y);
		else if (f1 == f2){
			if (x[0] > y[0]) swap(x, y);
		}
		int g = gcd(a[i], x[1]);
		dp[1][i] = { x[0] + 1, g, factors[g] };
		dp[0][i] = x;
		for (int j : {0, 1})
			if (dp[j][i][1] == 1 and dp[j][i][2] == 1)
				ans = min(ans, dp[j][i][0]);
	}
	cout << (ans==inf ? -1 : ans) << endl;
}
