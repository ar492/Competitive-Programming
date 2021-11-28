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
		int n, k; cin >> n >> k; // hole on point n
		vector<int> x(k);
		for (int i = 0; i < k; i++) cin >> x[i];
		sort(all(x));

		int timespent = 0;
		int cnt = 0;
		bool done = 0;
		for (int i = sz(x) - 1; i >= 0; i--){
			if (timespent >= x[i]){
				cout << cnt << endl;
				done = 1;
				break;
			}
			timespent += n-x[i];
			cnt++;
		}
		if (!done){
			cout << k << endl;
		}

	}
}
