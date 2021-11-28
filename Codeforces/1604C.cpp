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
		for (int i = 0; i < n; i++) cin >> a[i];

		int d = 2;
		bool done = 0;
		for (int i = 0; i < n && d <= 1e9; i++){
			if (a[i] % d == 0){
				cout << "NO" << endl;
				done = 1;
				break;
			}
			d = lcm(d, (i + 3));
		}

		if (!done){
			cout << "YES" << endl;
		}
		/*
		cout << "display divs: ";
		for (int i = 0; i < n; i++){ // first check if all 0s or 0 at first pos, then if odd # of zeros
			cout << (a[i] % (i + 2)) << " ";
		}cout << endl;
		*/
	}
}
