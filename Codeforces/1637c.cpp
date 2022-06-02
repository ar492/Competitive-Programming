#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int exe(){
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	if (n == 3 and a[1] & 1) return -1;
	bool f = 1;
	for (int i = 1; i < n - 1; i++){
		f &= (a[i] == 1);
	}
	if (f) return -1;
	int ans = 0;
	for (int i = 1; i < n - 1; i++){
		ans += a[i] / 2 + (a[i] & 1);
	}
	return ans;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	while (t--) cout << exe() << nl;
}


/*

-2 +1
+1 -2
+1 -2 +2
-2


*/