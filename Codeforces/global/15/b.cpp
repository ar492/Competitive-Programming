#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define nl "\n"
#define int long long
#define sz(X) ((int)(X.size()))
using namespace std;

int ops = 0;
struct games{
	int g1, g2, g3, g4, g5;
	int index;
};

bool cmp2(games a, games b){
	return ((a.g1 < b.g1) + (a.g2 < b.g2) + (a.g3 < b.g3) + (a.g4 < b.g4) + (a.g5 < b.g5)) >= 3;
}

bool cmp(games a, games b){
	/*
	ops++;
	if (ops > 3e5){
		return a.g1 < b.g1;
	}
*/
	return cmp2(a, b);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<games> g(n);
		for (int i = 0; i < n; i++){
			cin >> g[i].g1 >> g[i].g2 >> g[i].g3 >> g[i].g4 >> g[i].g5;
			g[i].index = i + 1;
		}
		sort(all(g), cmp);
		bool fine = true;
		for (int i = 1; i < n; i++){
			if (!cmp2(g[0], g[i])){
				fine = 0; break;
			}
		}
		if (!fine) cout << -1 << endl;
		else{
			cout << g[0].index << endl;
		}
		ops = 0;
	}
}