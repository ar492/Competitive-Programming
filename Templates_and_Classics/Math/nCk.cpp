
/*

	binomial coefficients in O(1)!
	precomputation:
		all factorials in O(n)
		all inverse factorials in O(nlog(mod))
	queries:
		simply use the cached factorial/invf values

*/
const int sz = 2e6;
const int mod = 1e9 + 7;
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
