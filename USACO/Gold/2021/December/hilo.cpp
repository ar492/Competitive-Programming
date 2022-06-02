// author: ar492
// created: 2022-01-10 18:26:01
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
	
	int n; cin >> n;
	map<int, int> hi, lo; // <x, y>
	vector<int> xpos(n + 1); // pos[p[i]]=i
	for (int i = 1; i <= n; i++){ // 1-index
		int u; cin >> u;
		hi[i] = u;
		xpos[u] = i;
	}
	
	int ans = 0;
	for (int x = 1; x <= n + 1; x++){ // x + 0.5 line. x goes from hi to lo
		lo[xpos[x]] = x;
		hi.erase(xpos[x]);
		
	}
}
