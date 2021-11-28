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
		int ans = 0;
		for (int i = 1; i <= n; i++){
			int u; cin >> u;
			ans = max(ans, u - i);
		}
		cout << ans << endl;
	}
}
