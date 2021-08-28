#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define nl "\n"
#define int long long
#define sz(X) ((int)(X.size()))
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s;
		cin >> s;
		string sorted = s;
		sort(all(sorted));
		int ans = 0;
		for (int i = 0; i < s.length(); i++) if (sorted[i] != s[i]) ans++;
		cout << ans << endl;
	}
}