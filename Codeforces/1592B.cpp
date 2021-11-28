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
		int x, n; cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> b = a;
		set<int> s;
		if (n >= 2 * x){
			cout << "yes" << endl;
			goto end;
		}
		sort(all(b));

		/*
		for (int i = 0; i < n - x; i++){
			s.insert(a[i]);
		}
		for (int i = 0; i < n - x; i++){
			if (!s.count(b[i])){
				cout << "no" << endl;
				goto end;
			}
		}*/
		for (int i = n - x; i < x; i++){
			if (a[i] != b[i]){
				cout << "no" << endl;
				goto end;
			}
		}
		cout << "yes" << endl;
		end:;
	}
}
