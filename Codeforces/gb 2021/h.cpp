// author: ar492
// created: 2021-12-29 12:09:09
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 150001;
const int mod = 998244353;
int n, x, a[sz], ans;

map<int, int> cmps;

namespace combo{
	int f[sz] = { 1 }, invf[sz];
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
	cin >> n >> x;
	int leq = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] <= x){
			leq++;
		}
	}
	//ans = (ans + (expo(2, leq) - 1)) % mod;

	vector<int> lack;
	for (int i = 0; i < 31; i++){
		if (x & (1ll << i)) continue;
		lack.emplace_back(i);
	}
	
	for (int i = 0; i < n; i++){
		// if (a[i] <= x) continue;
		int hsh = 0;
		for (int j : lack){
			if (a[i] & (1ll << j))
				hsh += (1ll << j);
		}
		cmps[hsh]++;
	}
	for (auto i : cmps){
		ans = (ans + (expo(2ll, i.second) - 1)) % mod;
	}
	cout << ans << endl;


}
