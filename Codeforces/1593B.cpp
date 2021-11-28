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
		string s; cin >> s;
		int n = len(s);
		int ans = 100;
		int cnt = 0;
		for (int i = 0; i < len(s); i++){
			if (s[i] != '0') cnt++;
		}
		for (int i = 0; i < len(s); i++){
			for (int j = i + 1; j < len(s); j++){
				auto p = make_pair( s[i], s[j] );
				if (p == make_pair('7', '5') || p == make_pair('2', '5') || p == make_pair('5', '0') || p == make_pair('0', '0')){
					ans = min(ans, j - i - 1 + (n - j - 1));
				}
			}
		}
		if (ans == 100) ans = 0;
		cout << ans << endl;
	}
}
