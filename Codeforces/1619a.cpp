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
		if (len(s) & 1){
			cout << "NO" << endl;
		}
		else{
			string x, y;
			for (int i = 0; i < len(s)/2; i++){
				x += s[i];
			}
			for (int i = len(s)/2; i < len(s); i++){
				y += s[i];
			}
			cout << (x == y ? "YES" : "NO") << endl;
		}

		
	}
}
