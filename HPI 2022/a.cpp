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
	vector<int> s;
	for (int i = 0; i < n;i++){
		int u; cin >> u; s.eb(u);
	}
	sort(all(s));
	cout << (s[sz(s) - 2] - s[1]) << endl;
}
