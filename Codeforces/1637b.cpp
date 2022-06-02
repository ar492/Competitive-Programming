// author: ar492
// created: 2022-02-12 20:20:17
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
		int ans = 0;
		for (int l = 0; l < n; l++){
			for (int r = l; r < n; r++){
				int itr = 0;
				bool add = 1;
				for (int j = l; j <= r; j++){
					if (v[j] != itr++){
						add = 0;
					}
				}
				ans += r - l + 1 + add;
				if (not add) ans += count(v.begin() + l, v.begin() + r + 1, 0);
			}
		}
		cout << ans << endl;
	}
}
