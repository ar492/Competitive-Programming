// author: ar492
// created: 2022-01-26 18:58:37
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

const int sz = 3e5 + 5;
int mp[sz], n;

struct xor_hsh{
	vector<int> ar, xors;
	void build(){
		for (int i = 0; i < n; i++)
			xors[i] = mp[ar[i]] ^ (i ? xors[i - 1] : 0);
	}
	xor_hsh(vector<int> v){
		ar = v; xors.resize(n); build();
	}
	inline int get(int a, int b){ // [a, b]
		return xors[b] ^ (a ? xors[a - 1] : 0);
	}
	inline void rev(){
		reverse(all(ar)); build();
	}
};

signed main(){	
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cin >> n;
	for (int i = 1; i <= n; i++) mp[i] = rand(1, 1e18);

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i], b[i] = i + 1;
	xor_hsh pre(b), input(a);

	int ans = 0;
	for (int j : {0, 1}){
		int mx = 0;
		for (int i = 0; i < n; i++){
			mx = (a[i] == 1 ? 1 : max(mx, a[i]));
			if (mx > i + 1) continue;
			ans += (pre.get(0, mx - 1) == input.get(i - mx + 1, i));
		}
		reverse(all(a));
		input.rev();
	}
	cout << ans - count(all(a), 1) << endl;
}
