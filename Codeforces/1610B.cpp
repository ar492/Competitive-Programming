#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;


vector<int> check(vector<int>& v){
	int n = sz(v);
	vector<int> bad;
	for (int i = 0; i < n; i++){
		if (v[i] != v[n - i - 1]){
			bad.emplace_back(v[i]);
			bad.emplace_back(v[n - i - 1]);
			return bad;
		}
	}
	return bad;
}

void exe(int n){
	vector<int> a(n);
	int mx = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	vector<int> bad = check(a);
	if (!sz(bad)){
		cout << "YES" << endl;
		return;
	}
	vector<int> v1, v2;
	for (int i : a){
		if (i != bad[0]) v1.emplace_back(i);
		if (i != bad[1]) v2.emplace_back(i);
	}
	if (!sz(check(v1)) or !sz(check(v2))){
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;


}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		exe(n);
	}
}
