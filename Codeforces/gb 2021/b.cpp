// author: ar492
// created: 2021-12-29 10:49:07
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
		string s; cin >> s;
		string ans = string() + s[0];
		bool z = 0;
		for (int i = 1; i < len(s); i++){
			if (s[i] < s[i - 1]){
				ans += s[i];
				z = 1;
			}
			else if (s[i] == s[i - 1] and z){
				ans += s[i];
			}
			else break;
		}
		string r = ans;
		reverse(all(r));
		cout << (string() + ans + r) << endl;
		
	}
}
