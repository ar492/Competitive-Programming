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

void exe(){
	int n; cin >> n;
	vector<array<int, 3>> items;
	for (int i = 0; i < n; i++){
		int li, ri, ci; cin >> li >> ri >> ci;
		items.push_back({ li, ri, ci });
	}
	int mn = 1e18, mx = -1e18;
	int sum = 0;
	int between = 0, not_between = 0;
	multiset<int> rs, ls;
	for (auto i : items){
		if (i[1] > mx or i[0] < mn){ // how to check duplicates
			if (i[1] > mx and i[0] < mn){
				sum -= not_between;
				between = not_between;
				not_between = 0;
			}
			else not_between += i[2];
			mx = max(mx, i[1]);
			mn = min(mn, i[0]);
			sum += i[2];
			rs.insert(i[1]);
			ls.insert(i[0]);
		}
		cout << "answer : "<<sum << nl;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		exe();
	}
}
