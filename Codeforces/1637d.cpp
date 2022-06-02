#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int exe(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	const int sz = 2e5;
	vector<int> knap(sz);
	knap[a[0]] = knap[b[0]] = 1;
	for (int i = 1; i < n; i++)
		for (int j = sz - 1; j >= 0; j--)
			knap[j + a[i]] |= knap[j],
			knap[j + b[i]] |= knap[j], knap[j] = 0;
	int sum = accumulate(all(a), 0) + accumulate(all(b), 0);
	auto cost = [&](int as, int s = 0){
		for (int i = 0; i < n; i++)
			s += (a[i] * a[i] + b[i] * b[i]) * (n - 2);
		return s + as * as + (sum - as) * (sum - as);
	};
	for (int i = 0; i < sz; i++)
		for (int j : {sum / 2 + i, sum / 2 - i})
			if (knap[j])
				return cost(j);
}
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	while (t--) cout << exe() << nl;
}
// minimize difference between a and b
// make sum of a as close to (sum(a) + sum(b))/2 as possible