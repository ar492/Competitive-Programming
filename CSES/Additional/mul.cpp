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
	
	int n; cin >> n;
	int lo = 1, hi = 1e18, ans = -1;
	while (lo <= hi){
		int m = lo + hi >> 1ll;
		int g = 0;
		for (int r = 1; r <= n; r++){
			g += max(0ll, n - m / r);
		}
		if (g <= ((n * n) / 2ll)){
			ans = m, hi = m - 1;
		}
		else lo = m + 1;
	}
	cout << ans << endl;	
}
