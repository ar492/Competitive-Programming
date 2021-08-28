/*
	author: ar492
	created: 08/03/2021 at 15:24:56
*/

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 3e6 + 5;
int n, q, num[sz], res[sz];

namespace combo{
	const int mod = 1e9 + 7;
	int f[sz] = { 1 };
	int invf[sz];
	int expo(int a, int b){
		if (a == 0) return b == 0;
		int ans = 1;
		while (b){
			if (b & 1) ans = (ans * a) % mod;
			b >>= 1LL;
			a = (a * a) % mod;
		}
		return ans;
	}
	int inv(int a){
		return expo(a, mod - 2);
	}
	void setup_combo(){
		for (int i = 1; i < sz; i++) f[i] = (i * f[i - 1]) % mod;
		for (int i = 0; i < sz; i++) invf[i] = inv(f[i]);
	}
	int choose(int a, int b){
		if (a < b) return 0;
		return (((f[a] * invf[b]) % mod) * invf[a - b]) % mod;
	}
}
using namespace combo;


signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	setup_combo();
	cin >> n >> q;
	int lim = 3 * n + 3;
	for (int i = 0; i <= lim; i++) num[i] = choose(lim, i);

	auto sub = [&](int a, int b){
		num[a] = (num[a] - b + mod * 5) % mod;
	};
	sub(lim, 1); sub(lim - 1, 3); sub(lim - 2, 3); sub(lim - 3, 1);
	for (int i = 0; i < lim - 3; i++){
		int mul = num[i];
		res[3 * n - i - 1] = mul;
		sub(i, mul); sub(i + 1, 3 * mul); sub(i + 2, 3 * mul);
	}
	while (q--){
		int x; cin >> x;
		cout << res[x - 1] << nl;
	}
}