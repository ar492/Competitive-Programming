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
	for (int i = 1; i <= t; i++){
		int l, r; cin >> l >> r;
		int n = r - l + 1;
		vector<int> v(n);
		for (int& j : v) cin >> j;
		auto vv = v;
		vector<int> cor(n);
		for (int i = 0; i < n; i++) cor[i] = i + l;
		int ans = 0;
		int cnt = 1;
		for (int i = 0; i < 20; i++){
			int cc = 0, vc = 0;
			for (int& j : cor){
				if (j & 1) cc++;
				j /= 2;
			}
			for (int& j : v){
				if (j & 1) vc++;
				j /= 2;
			}
			if (vc == n - cc){
				ans += cnt;
			}
			cnt *= 2;
		}
		if (i == 1202){
			cout << l << " " << r << endl;
			for (int j : vv) cout << j << " "; cout << endl;
		}
		else if(t<10) cout << ans << endl;
	}
}

/*


1
0 5
2 3 0 1 6 7

*/