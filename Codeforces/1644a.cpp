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
		map<char, int> m;
		for (int i = 0; i < 6; i++){
			char c; cin >> c; m[c] = i;
		}
		if (m['r'] < m['R'] and m['b'] < m['B'] and m['g'] < m['G']){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}
