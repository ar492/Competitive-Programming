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
		string s; cin >> s;
		int a = 0;
		for (int i = 0; i < len(s) - 1; i++){
			if (s[i] == '0' and s[i + 1] == '0') a++;
		}
		int b = 0;
		for (int i = 0; i < len(s) - 2; i++){
			if (s[i] == '0' and s[i + 1] == '1' and s[i + 2] == '0') b++;
		}
		cout << 2 * a + b << endl;
	}
}
