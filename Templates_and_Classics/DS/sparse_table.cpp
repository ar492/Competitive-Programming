/*
	https://cses.fi/problemset/task/1647/
	author: ar492
	created: 08/01/2021 at 14:00:35
*/
 
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;
 
int n, q;
const int nmax = 2e5 + 5;
int a[nmax];
int sparse[nmax][30]; // 1 indexed
int logs[nmax];
 
int f(int p1, int p2){
	return min(p1, p2);
}

void build(){
	for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
	for (int i = 1; i <= n; i++) sparse[i][0] = a[i];
	for (int dep = 1; dep < 30; dep++){
		for (int i = 1; i + (1 << dep - 1) <= n; i++){
			sparse[i][dep] = f(sparse[i][dep - 1], sparse[i + (1 << dep - 1)][dep - 1]);
		}
	}
}
 
int query(int l, int r){
	int lg = logs[r - l + 1];
	return(f(sparse[l][lg], sparse[r - (1 << lg) + 1][lg]));
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build();
	while (q--){
		int l, r; cin >> l >> r;
		cout << query(l, r) << endl;
	}
}