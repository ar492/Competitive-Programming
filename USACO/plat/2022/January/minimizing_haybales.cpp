#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int n, k;
vector<int> v;

void pr(){
	for (int i = 0; i < n; i++){
		cout << (v[i]) << nl;
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	vector<array<int, 2>> indices;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		int u; cin >> u; v.eb(u);
		indices.pb({ v[i], i });
	}
	sort(all(indices));
	reverse(all(indices));

	for (auto x : indices){
		int i = x[1];
		int sw = 0; // index to swap with
		for (int j = i - 1; j >= 0; j--){
			if (not (abs(v.at(i) - v.at(j)) <= k)){
				sw = j + 1; break;
			}
		}
		//cout << "sw is " << sw << " for i = " << i << endl;
		if (v.at(sw) > v.at(i)){
			vector<int> vv;
			for (int j = 0; j < sw; j++){
				vv.eb(v[j]);
			}
			vv.eb(v[i]);
			for (int j = sw; j < n; j++){
				if (j == i) continue;
				vv.eb(v[j]);
			}
			v = vv;
		}
		//pr();
	}
	pr();

}
