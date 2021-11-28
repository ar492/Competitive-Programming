#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

int dif(char a, char b){
	int x = ((int)((b - a) + 26)) % 26;
	return min(x, 26 - x);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		string s, f; cin >> s >> f;
		int ans = 0;
		for (char i : s){
			int mn = 50;
			for (char j : f){
				mn = min(mn, dif(i, j));
			}
			ans += mn;
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}
