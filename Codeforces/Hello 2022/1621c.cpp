// author: ar492
// created: 2022-01-03 10:35:33
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;

	while (t--){
		int n; cin >> n;

		vector<int> vis(n + 1), p(n + 1);
		for (int i = 1; i <= n; i++){
			if (vis[i]) continue;
			vector<int> cycle;
			while (1){
				cout << "? " << i << endl;
				int qi; cin >> qi;
				if (vis[qi]) break;
				vis[qi] = 1;
				cycle.eb(qi);
			}
			for (int j = 0; j < sz(cycle); j++)
				p[cycle[j]] = cycle[j + 1];
			p[cycle.back()] = cycle[0];
		}
		cout << "! ";
		for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? nl : " ");
		cout.flush();
		
	}
}
