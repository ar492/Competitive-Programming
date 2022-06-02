#include<bits/stdc++.h>
#define aint(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define ll long long
#define nl "\n"
using namespace std;

const short power = 9973;
const int mod = (ll)1e9 + 7;
const short MXN = 1e3 + 1;
int powers[MXN];
short n, m;

int fast_mod(const ll input) {
    // apply the modulo operator only when needed
    // (i.e. when the input is greater than the ceiling)
    return input >= mod ? input % mod : input;
    // NB: the assumption here is that the numbers are positive
}

int getmod(const int& a){ return fast_mod(a%mod + mod); }


void pre(){
	int pow = 1;
	for (int i = 0; i < MXN; i++, pow = ((ll)pow * power) % mod){
		powers[i] = pow;
		//cout << powers[i] << endl;
	}
}


struct polyhash{
	array<int, MXN> s, hsh;
	void prehash(){
		for (short i = 0; i < sz(s); i++)
			hsh[i]=fast_mod(fast_mod((ll)(i ? hsh[i - 1] : 0) * power) + s[i]);
	}
	int gethash(short a, short b){ // [a, b] inclusive of a, b
		if (!a) return hsh[b];
		return
			getmod(hsh[b] - fast_mod((ll)powers[b - a + 1] * hsh[a - 1]));
	}
} hashes[MXN];

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	//ifstream cin("inp.txt");
	pre();
	cin >> n >> m;
	for (short i = 0; i < m; i++){
		string s; cin >> s;
		for (int j = 0; j < len(s); j++){
			hashes[i].s[j] = (s[j] - 'A' + 1);
		}
		hashes[i].prehash();
	}

	short lo = 0, hi = n - 1, ans = -2;
	while (lo <= hi){
		short mid = lo + hi >> 1ll;
		unordered_set<int> hashset;
		map<int, bool> mp;
		for (short j = 0; j < n; j++){
			for (short i = 1; i < m; i++){
				mp[hashes[i].gethash(j, min(j + mid, n - 1))] = 1;
				// hashset.insert(hashes[i].gethash(j, min(j + mid, n - 1)));
			}
		}

		short tot = n;
		for (short i = 0; i < n; i++){
			if (mp[hashes[0].gethash(i, min(i + mid, n - 1))]){
				tot--;
			}
		}
		if (tot >= n / 2 + (n & 1)){
			hi = (ans = mid) - 1;
		}
		else{
			lo = mid + 1;
		}
	}
	cout << ans + 1 << endl;
}
