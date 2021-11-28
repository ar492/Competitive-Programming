
// rolling poly hash for string matching
// aka rabin-karp
// https://cses.fi/problemset/task/1753/

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define pb push_back
#define eb emplace_back
#define int long long
#define nl "\n"
using namespace std;


// p[i] is prefix hash
// h[2] = a[0]p^2 + a[1]p^1 + a[2]p^0
// h[3] = a[0]p^3 + a[1]p^2 + a[2]p^1 + a[3]p^0
// ...
// h[i] = (h[i-1]p + a[i])%mod

struct polyhash{
	string s;
	const int power = 53, hmod = 1e10 + 2; // they should be opposite in parity to have better chance at avoiding collisions
	vector<int> powers, h;
	inline int getmod(int a, int b){
		return (a % b + b) % b;
	}
	void prehash(){
		int powitr = 1;
		for (int i = 0; i < len(s); i++, powitr = (powitr * power) % hmod){
			powers.emplace_back(powitr);
			h.emplace_back(((i ? h[i - 1] : 0) * power + s[i]) % hmod);
		}
	}
	inline int gethash(int a, int b){ // [a, b] inclusive of a, b
		if (!a) return h[b];
		return getmod(h[b] - powers[b - a + 1] * h[a - 1], hmod);
	}
};

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	polyhash a, b;
	cin >> a.s >> b.s;
	a.prehash();
	b.prehash();
	int h = b.gethash(0, len(b.s) - 1);
	int ans = 0;
	for (int i = 0; i + len(b.s) - 1 < len(a.s); i++){
		ans += (a.gethash(i, i + len(b.s) - 1) == h);
	}
	cout << ans << endl;

}
