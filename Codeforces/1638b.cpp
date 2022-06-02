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
		int n; cin >> n;
		vector<int> e, es, o, os;
		for (int i = 0; i < n; i++){
			int u; cin >> u;
			if (u & 1){
				o.eb(u);
				os.eb(u);
			}
			else{
				e.eb(u);
				es.eb(u);
			}
		}
		sort(all(os));
		sort(all(es));
		if (o == os and e == es){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}