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
	
	int t; cin>>t;
	while (t--){
		int n; cin >> n;
		vector<int> v(n);
		for (int& i : v) cin >> i;

		int ind = 0;
		for (int i = 0; i < n; i++){
			if (v[i] != i + 1){
				ind = i; break;
			}
		}
		int mn = 1e18;
		int mind = -1;
		for (int i = ind; i < n; i++){
			if (v[i] < mn){
				mn = v[i];
				mind = i;
			}
		}
		reverse(v.begin() + ind, v.begin() + mind + 1);
		for (int i = 0; i < n; i++){
			cout << v[i] << (i == n - 1 ? "\n" : " ");
		}

	}
}
