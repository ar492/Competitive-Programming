#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	set<int> s;
	for (int i = 1; i < 31625; i++){
		s.insert(i * i);
		s.insert(i * i * i);
	}
	vector<int> v;
	for (int i : s) v.emplace_back(i);
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << (upper_bound(v.begin(), v.end(), n) - v.begin()) << endl;
		
	}
}
