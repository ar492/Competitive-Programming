#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n), b(n);
		map<int, int> ac, bc;
		for (int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
			ac[a[i]]++;
			bc[b[i]]++;
		}
		int ans = (n * (n - 1) * (n - 2)) / 6;
		for (int i = 0; i < n; i++){
			ans -= (ac[a[i]] - 1) * (bc[b[i]] - 1);
		}
		cout << ans << endl;
	}
}
