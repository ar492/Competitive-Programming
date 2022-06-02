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
		set<vector<int>> ans;
		auto test = [](vector<int> x){
			for (int i = 2; i < sz(x); i++){
				if (x[i - 2] + x[i - 1] == x[i]){
					return false;
				}
			}
			return true;
		};
		vector<int> v;
		for (int i = 1; i <= n; i++) v.eb(i);
		for (int z : {1, 2}){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					swap(v[i], v[j]);
					if (test(v)){
						ans.insert(v);
					}
					swap(v[i], v[j]);
				}
			}
			reverse(all(v));
		}
		int cnt = 0;
		for (auto i : ans){
			if(cnt==n) break;
			for (auto j : i) cout << j << " ";
			cout << endl;
			cnt++;
		}
	}
}
