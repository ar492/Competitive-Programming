#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int n; cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int& i : v){
		cin >> i; sum += i;
	}

	map<int, int> mp;
	for (int k = 1; k <= n; k++){
		int ptr = 0;
		while (ptr < n){
			mp[k] += v[ptr];
			ptr += k;
		}
	}
	for (int k = 1; k <= n; k++){
		int ans = 0;
		if (gcd(n, k) != 1){
			ans += mp[gcd(n, k)];
		}
		else ans = sum;
		cout << ans << endl;
	}
}
