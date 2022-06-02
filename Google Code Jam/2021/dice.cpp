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
	for (int _ = 1; _ <= t; _++){
		cout << "Case #" << _ << ": ";
		int n; cin >> n;
		vector<int> v(n);
		for (int& i : v) cin >> i;
		sort(all(v));
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (v[i] >= ans + 1)
				ans++;
		cout << ans << endl;

	}
}
