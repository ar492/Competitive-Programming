// author: ar492
// created: 2021-12-29 10:45:45
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
		vector<int> a(n);
		for (int& i : a){
			cin >> i;
		}
		set<int> s;
		sort(all(a));
		for (int i = 0; i < n; i++){
			if (!s.count(a[i])){
				s.insert(a[i]);
			}
			else s.insert(-a[i]);
		}
		cout << sz(s) << endl;


	}
}
