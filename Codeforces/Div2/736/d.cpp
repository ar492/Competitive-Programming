/*
	author: ar492
	created: 08/01/2021 at 13:38:19
*/

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 2e5 + 5;
int a[sz], n;
int sparse[sz][30]; // 1 indexed
int logs[sz];

int f(int p1, int p2){
	return gcd(p1, p2);
}

void build(){
	for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
	for (int i = 1; i <= n; i++) sparse[i][0] = a[i];
	for (int dep = 1; dep < 30; dep++)
		for (int i = 1; i + (1 << dep - 1) <= n; i++)
			sparse[i][dep] = f(sparse[i][dep - 1], sparse[i + (1 << dep - 1)][dep - 1]);
}

int query(int l, int r){
	int lg = logs[r - l + 1];
	return(f(sparse[l][lg], sparse[r - (1 << lg) + 1][lg]));
}

bool fine(int m){
	for (int i = m; i <= n; i++) if (query(i - m + 1, i) != 1) return true;
	return false;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		n--;
		for (int i = 1; i <= n; i++) a[i] = abs(a[i] - a[i + 1]);
		build();
		int ans = 0, lo = 1, hi = n;
		while (lo <= hi){
			int m = lo + hi >> 1;
			if (fine(m)) ans = m, lo = m + 1;
			else hi = m - 1;
		}
		cout << ans + 1 << endl;
	}
}