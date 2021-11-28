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
		vector<array<int, 2>> a(n);
		for (auto& i : a) cin >> i[0] >> i[1];


		auto fine = [&](int m){
			int rem = m;
			for (int i = 0; i < n; i++){
				if (a[i][0] >= rem - 1 and a[i][1] >= m - rem) rem--;
			}
			return rem <= 0;
		};

		int lo = 1, hi = n, ans = 1;
		while (lo <= hi){
			int m = lo + hi >> 1ll;
			fine(m) ? lo = (ans = m) + 1 : hi = m - 1;
		}
		cout << ans << endl;
	}
}
