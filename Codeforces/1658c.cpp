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
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> c(n);
		for (int& i : c) cin >> i;
		string ans = "YES";
		for (int i = 0; i < n - 1; i++){
			if ( c[i] + 1 <= c[i + 1] + 1 or c[i + 1] == 1){
				
			}
			else{
				ans = "NO";
			}
		}
		int cnt = 0;
		for (int i : c) if (i == 1) cnt++;
		if (cnt != 1) ans = "NO";

		cout << ans << endl;

	}
}
