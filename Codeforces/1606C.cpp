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
		int n, k; cin >> n >> k;
		vector<int> a(10);
		for (int i = 0; i < n; i++){
			int u; cin >> u;
			a[u] = 1;
		}
		int ans = 1e18;
		for (int i = 0; i < 10; i++){
			if (!a[i]){
				int ten = 10;
				for (int j = i - 1; j >= 0; j--, ten *= 10){
					if (a[j] == 1){
						a[i] = ten; break;
					}
				}
			}
		}
		int p10[10];
		int ten = 1;
		for (int i = 0; i < 10; i++){
			p10[i] = ten; ten *= 10;
		}
		for (int i = 9; i >= 0; i--){
			if (a[i] <= k){
				
			}
		}
		cout << "answer is " << ans << endl;

	}
}
