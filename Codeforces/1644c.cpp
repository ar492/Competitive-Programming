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
	
	int t; cin>>t;
	while (t--){
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		vector<int> p(n);
		p[0] = a[0];
		for (int i = 1; i < n; i++) p[i] = (p[i - 1] + a[i]);

		vector<vector<int>> v(n); // v[i][j] is sum of jth immidiate suffix from i

		for (int i = 0; i < n; i++){
			for (int j = i; j < n; j++){
				int sum = p[j] - (i ? p[i - 1] : 0ll);
				v[i].eb(sum);
			}
		}
		vector<int> mxs(n, -1e18); // mxs[i] = max sum subarray len i
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (j >= sz(v[i])) continue;
				mxs[j] = max(mxs[j], v[i][j]);
			}
		}

		
		cout << max(0ll, *max_element(all(mxs))) << " ";
		for (int i = 1; i <= n; i++){
			int sum = 0;
			for (int j = 0; j < n; j++){
				sum = max(sum, mxs[j] + (min(j + 1, i) * k));
			}
			cout << max(0ll, sum) << " ";
		}cout << endl;
	}
}
