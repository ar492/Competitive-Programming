#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
#define eb emplace_back
using namespace std;

int getmod(const int a, const int b){ return (a % b + b) % b; }

const int power = 89417;
vector<int> powers[2];
array<const int, 2> mods = { 1000000007, 1000000009 };

struct polyhash{
	vector<int> s, hsh[2];
	void pre(){
		int pow1 = 1, pow2 = 1;
		for (int i = 0; i < 2e5 + 2; i++, pow1 = (pow1 * power) % mods[0], pow2 = (pow2 * power) % mods[1])
			powers[0].eb(pow1), powers[1].eb(pow2);
	}
	array<int, 2> prehash(){
		for (int j : {0, 1})
			for (int i = 0; i < sz(s); i++)
				hsh[j].eb((((i ? hsh[j][i - 1] : 0) * power) % mods[j] + s[i]) % mods[j]);
		return { hsh[0].back(), hsh[1].back() };
	}
	inline array<int, 2> gethash(int a, int b){ // [a, b] inclusive of a, b
		if (!a) return { hsh[0][b], hsh[1][b] };
		return {
			getmod(hsh[0][b] - (powers[0][b - a + 1] * hsh[0][a - 1]) % mods[0], mods[0]),
			getmod(hsh[1][b] - (powers[1][b - a + 1] * hsh[1][a - 1]) % mods[1], mods[1])
		};
	}
};

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	string n, h; cin >> n >> h;
	if (len(n) > len(h)) return cout << "0\n", 0;
	polyhash needle, hay_window, full_hay;
	needle.pre();
	needle.s.assign(26, 0);
	hay_window.s.assign(26, 0);
	for (char c : h) full_hay.s.eb(c - 'a');
	for (int i = 0; i < len(n); i++){
		needle.s[n[i] - 'a']++;
		hay_window.s[h[i] - 'a']++;
	}
	full_hay.prehash();
	needle.prehash();
	auto nhash = needle.prehash(); // needle freqhash
	auto hhash = hay_window.prehash(); // haystack window freqhash

	set<array<int, 2>> distinct;
	if (nhash == hhash)
		distinct.insert(full_hay.gethash(0, len(n) - 1));

	for (int i = len(n); i < len(h); i++){
		for (int j : {0, 1}){
			hhash[j] -= powers[j][26 - (h[i - len(n)] - 'a') - 1]; // remove h[i-len(n)] from hhash
			hhash[j] += powers[j][26 - (h[i] - 'a') - 1]; // add h[i] to hhash
			hhash[j] = getmod(hhash[j], mods[j]);
		}
		if (nhash == hhash)
			distinct.insert(full_hay.gethash(i - len(n) + 1, i));
	}
	cout << sz(distinct) << endl;
}
