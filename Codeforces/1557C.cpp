#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)((x).size())

const int sz = 2e5 + 5;
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
	int t; cin >> t;
	setup_combo();
	while(t--){
		int n, k; cin >> n >> k;
		int ans = 0;
		for(int i = 0; i <= n; i += 2){
			ans = (ans + choose(n, i)) % mod;
		}
		if(n & 1){
			cout << expo((ans + 1) % mod, k) << endl;
		}
		else{
			ans--;
			int realans = 0;
			for(int i = 1; i <= k; i++){
				realans = (realans + (expo(ans, i - 1) * expo(2, (k - i) * n)) % mod) % mod;
			}
			cout << (realans + expo(ans, k)) % mod << endl;
		}
	}
}
