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
		int n; cin >> n; vector<int> p(n);
		for (int& i : p) cin >> i;
		vector<int> smn(n, p[n-1]);
		for (int i = n - 2; i > 0; i--)
			smn[i] = min(smn[i + 1], p[i]);
		int ans = 0, mx = 0;
		for (int i = 0; i < n; i++){
			int ind = upper_bound(all(smn), p[i]) - smn.begin() - 1;
			ans += ((mx = max(mx, ind)) == i);
		}
		cout << ans << nl;
	}
}