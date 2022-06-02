#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;


void exe(){
	int n, k; cin >> n >> k;
	string s; cin >> s;

	if (s.back() != '1'){
		for (int i = n - 1; i >= 0; i--){
			if (s[i] == '1' and k - (((n - 1) - i)) >= 0){
				string ss;
				for (int j = 0; j < i; j++){
					ss += s[j];
				}
				for (int j = i + 1; j < n; j++){
					ss += s[j];
				}
				ss += '1';
				s = ss;
				k -= ((n - 1) - i);
				break;
			}
		}
	}
	if (s[0] != '1'){
		for (int i = 0; i < n - 1; i++){
			if (s[i] == '1' and k - i >= 0){
				string ss = "1";
				for (int j = 0; j < i; j++){
					ss += s[j];
				}
				for (int j = i + 1; j < n; j++){
					ss += s[j];
				}
				s = ss;
				k -= i;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++){
		ans += ((s[i] - '0') * 10 + (s[i + 1] - '0'));
	}
	cout << ans << endl;

}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		exe();
	}
}