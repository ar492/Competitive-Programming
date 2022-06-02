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
	
	int n, q; cin >> n >> q;
	vector<int> a;
	for (int i = 0; i < n;i++){
		int u; cin >> u; a.eb(u);
	}
	while (q--){
		int l, r; cin >> l >> r;
		l--; r--;
		map<int, int> mp;
		for (int i = l; i <= r; i++){
			mp[a[i]]++;
		}
		int mode = 1e18;
		int freq = -1e18;
		for (auto i : mp){
			if (i.second > freq){
				freq = i.second;
				mode = i.first;
			}
			else if (i.second == freq){
				mode = min(mode, i.first);
			}
		}
		cout << mode << endl;
	}
}
