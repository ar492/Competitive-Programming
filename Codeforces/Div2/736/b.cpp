/* 
	author: ar492 
	created: 08/01/2021 at 10:42:12
*/

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
		string enemy, me;
		cin >> enemy >> me;
		vector<int> vis(n);
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (me[i] == '1'){
				if (i > 0 && vis[i - 1] == 0 && enemy[i - 1] == '1'){
					vis[i - 1] = 1; ans++;
				}
				else if (enemy[i] == '0' && vis[i] == 0){
					vis[i] = 1; ans++;
				}
				else if (i < n + 1 && vis[i + 1] == 0 && enemy[i + 1] == '1'){
					vis[i + 1] = 1; ans++;
				}
			}
		}
		cout << ans << endl;
	}
}

/*

1
6
110011
010011


1
3
111
111

1
4
1110
0111

1110
0111
*/