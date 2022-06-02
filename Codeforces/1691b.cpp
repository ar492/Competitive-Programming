#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

void exe(){
	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	for (int i = 1; i < n - 1; i++){
		if (v[i] != v[i - 1] and v[i] != v[i + 1]){
			cout << -1 << endl; return;
		}
	}
	if (v[0] != v[1] or v[n - 1] != v[n - 2]){
		cout << -1 << endl; return;
	}
	int cur = v[0];
	vector<int> ans;
	for (int i = 0; i < n; i++){
		//cout << "i = " << i << endl;
		deque<int> d;
		if (v[i] != cur) cur = v[i];
		while (i < n and v[i] == cur){
			i++; d.eb(i);
		}
		//cout << "d is ";
		//for (int j : d) cout << j << " "; cout << endl;
		int x = d.back();
		d.pop_back();
		d.push_front(x);
		for (int j : d) ans.eb(j);
		i--;
	}
	for (int i : ans) cout << i << " "; cout << endl;

}
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin>>t;
	while (t--){
		exe();
	}
}
