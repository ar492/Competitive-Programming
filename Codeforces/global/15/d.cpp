#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define nl "\n"
#define int long long
#define sz(X) ((int)(X.size()))
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		bool done = false;
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 1; i < (1 << n); i++){
			vector<int> s;
			for (int j = 0; j < n; j++){
				int mask = 1 << j;
				if (i & mask)
					s.push_back(a[j]);
			}
			for (int j = 1; j < (1 << sz(s)); j++){
				set<int> indices;
				for (int k = 0; k < sz(s); k++){
					int mask2 = 1 << k;
					if (j & mask2)
						indices.insert(k);
				}
				int sum = 0;
				for (int k = 0; k < sz(s); k++){
					if (indices.count(k)) sum += s[k];
					else sum -= s[k];
				}
				if (sum == 0 && !done){
					cout << "YES" << endl; done = true;
				}
			}	
		}
		if (!done){
			cout << "NO" << endl;
		}
	}
}