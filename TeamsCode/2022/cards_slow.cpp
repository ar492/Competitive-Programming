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
	vector<int> v(n);
	for (int& i : v) cin >> i;
	for (int k = 1; k <= n; k++){
		set<int> flip;
		int ptr = 0;
		while (true){
			if (flip.count(ptr)) break;
			flip.insert(ptr);
			ptr += k;
			ptr %= n;
		}
		int sum = 0;
		for (int i : flip) sum += v[i];
		cout << sum << endl;
	}

}
