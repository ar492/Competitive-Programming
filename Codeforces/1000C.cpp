/*
	author: ar492
	created: 08/04/2021 at 00:25:35
*/

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int n; cin >> n;
	vector<array<int, 2>> points; // <pos, 0 if start, 1 if end>
	vector<int> ans(n + 1);
	map<int, int> da;
	for (int i = 0; i < n; i++){
		int l, r; cin >> l >> r;
		da[l]++; da[r + 1]--;
	}
	int prev = -1, prevpos = -1;
	for (auto& i : da){
		if (prev != -1) i.second += prev;
		if (prevpos != -1) ans[da[prevpos]] += i.first - prevpos;
		prev = i.second;
		prevpos = i.first;
	}
	for (int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
}
