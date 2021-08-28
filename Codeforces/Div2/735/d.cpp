#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(X) (int)((X).size())
#define len(X) (int)((X).length())
#define all(X) (X).begin(), (X).end()

signed main(){
	int t; cin >> t;
	while (t--){
		string ans;
		int n; cin >> n;
		for (int i = 0; i < n / 2; i++) ans += 'a';
		ans += 'b';
		for (int i = n / 2; i < n - 1; i++) ans += 'a';
		if (n & 1) ans[len(ans) - 1] = 'z';
		cout << ans << endl;
	}
}