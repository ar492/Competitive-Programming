// author: ar492
// created: 2022-02-12 19:55:22
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
		vector<int> v(n);
		for (int& i : v) cin >> i;
		vector<int> x = v;
		sort(all(v));
		if (x == v){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
}
