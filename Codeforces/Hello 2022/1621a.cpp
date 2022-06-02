// author: ar492
// created: 2022-01-03 09:33:32
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

char g[40][40];
void exe(){
	int k, n; cin >> n >> k;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			g[i][j] = '.';
		}
	}
	int p = 0;
	for (int i = 0; i < n; i += 2){
		if (p == k) break;
		g[i][i] = 'R';
		p++;
	}
	if (p != k){
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << g[i][j];
		}cout << endl;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		exe();
	}
}
