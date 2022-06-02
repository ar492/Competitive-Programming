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
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> v(n);
		for (int& i : v) cin >> i;
		auto x = v;
		sort(all(x));
		if (x == v){
			cout << 0 << endl;
		}
		else{
			if (v[n - 2] <= v[n - 1] and v[n - 2] - v[n - 1] <= v[n - 2] and v[n - 2] - v[n - 1] <= v[n - 1]){
				cout << n - 2 << endl;
				for (int i = 1; i <= n - 2; i++){
					cout << i << " " << n - 1 << " " << n << endl;
				}
			}
			else{
				cout << -1 << endl;
			}
		}
	}
}