// author: ar492
// created: 2022-01-16 10:01:12
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
		vector<int> k(n), h(n), smax(n);
		for (int i = 0; i < n; i++){
			cin >> k[i];
		}
		for (int i = 0; i < n; i++){
			cin >> h[i];
		}
		smax[n - 1] = h[n - 1] - k[n - 1];
		for (int i = n - 2; i >= 0; i--){
			smax[i] = max(smax[i + 1], h[i] - k[i]);
		}

		int ans = 0;
		int prvmn = 0;
		for (int i = 0; i < n; i++){
			int raw_mn = max(h[i], k[i] + smax[i]);
			int cost = 1e18;
			int dif = k[i] - (i ? k[i - 1] : 0ll);

			int mn = raw_mn;
			if (dif >= raw_mn){
				cost = min(cost, (raw_mn * (raw_mn + 1)) / 2ll);
			}
			else{
				mn = prvmn + dif;
				assert(mn >= raw_mn);
				cost = min(cost, ((mn * (mn + 1)) / 2ll) - (prvmn * (prvmn + 1)) / 2ll);
			}

			ans += cost;
			prvmn = mn;
		}

		cout <<ans << endl;


	}
}
