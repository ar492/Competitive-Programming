#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(X) (int)((X).size())
#define len(X) (int)((X).length())
#define all(X) (X).begin(), (X).end()

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 0; i < n - 1; i++) ans = max(ans, a[i] * a[i + 1]);
		cout <<ans << endl;
	}
}