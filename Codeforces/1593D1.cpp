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
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n - 1; i++){
			a[i] = abs(a[i + 1] - a[i]);
		}
		a.pop_back();
		int ans = a[0];
		for (int i : a){
			ans = gcd(ans, i);
		}
		if(ans==0) ans--;
		cout << ans << endl;
	}
}