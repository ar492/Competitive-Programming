// https://dmoj.ca/problem/ioi06p1
// :sob: wasted time on dumb mistake. thought it was mle so
// .. unnecessarily changed stuff
// also dont even need double hash for this since g leq 3000

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define ll long long
#define nl "\n"
#define eb emplace_back

using namespace std;

ll getmod(const ll a, const ll b){ return (a % b + b) % b; }

const ll power = 89417;
array<const ll, 2> mods = { 1000000007, 1000000009 };
const int mx = 1e3 + 2;
int powers[2][mx];

void pre(){
	int pow1 = 1, pow2 = 1;
	for (int i = 0; i < mx; i++, pow1 = (pow1 * power) % mods[0], pow2 = (pow2 * power) % mods[1]){
		powers[0][i] = pow1; powers[1][i] = pow2;
	}
}

struct polyhash{
	vector<ll> s, hsh[2];
	array<ll, 2> prehash(){
		for (short j : {0, 1})
			for (int i = 0; i < sz(s); i++)
				hsh[j].eb((((i ? hsh[j][i - 1] : 0) * power) % mods[j] + s[i]) % mods[j]);
		return { hsh[0].back(), hsh[1].back() };
	}
	array<ll, 2> gethash(int a, int b){ // [a, b] inclusive of a, b
		if (!a) return { hsh[0][b], hsh[1][b] };
		return {
			getmod(hsh[0][b] - (powers[0][b - a + 1] * hsh[0][a - 1]) % mods[0], mods[0]),
			getmod(hsh[1][b] - (powers[1][b - a + 1] * hsh[1][a - 1]) % mods[1], mods[1])
		};
	}
};

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int a, b; string n, h; cin >> a >> b >> n >> h;
	polyhash needle, hay_window;
	pre();
	needle.s.assign(59, 0);
	hay_window.s.assign(59, 0);
	for (int i = 0; i < len(n); i++){
		needle.s[n[i] - 'A']++;
		hay_window.s[h[i] - 'A']++;
	}
	needle.prehash();
	auto nhash = needle.prehash(); // needle shash
	auto hhash = hay_window.prehash(); // haystack window freqhash

	int ans = 0;
	ans += (nhash == hhash);

	for (int i = len(n); i < len(h); i++){
		for (short j : {0, 1}){
			hhash[j] -= powers[j][59 - (h[i - len(n)] - 'A') - 1]; // remove h[i-len(n)] from hhash
			hhash[j] += powers[j][59 - (h[i] - 'A') - 1]; // add h[i] to hhash
			hhash[j] = getmod(hhash[j], mods[j]);
		}
		ans += (nhash == hhash);
	}
	cout << ans << endl;
}