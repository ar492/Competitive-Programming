#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;


struct spt{ // everything 0-index but 1-index under the hood so dont worry
	int n;
	vector < int > logs;
	vector < vector < int >> sparse; // 1 - index
	int f(int p1, int p2){ return max(p1, p2); }
	spt(vector < int >& a){ // a is 0-index
		n = sz(a);
		logs.resize(n + 1), sparse.resize(n + 1, vector < int >(30));
		for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
		for (int i = 1; i <= n; i++) sparse[i][0] = a[i - 1];
		for (int dep = 1; dep < 30; dep++)
			for (int i = 1; i + (1 << dep - 1) <= n; i++)
				sparse[i][dep] = f(sparse[i][dep - 1], sparse[i + (1 << dep - 1)][dep - 1]);
	}
	int query(int l, int r){ // [l, r] 0 indexed
		l++, r++;
		int lg = logs[r - l + 1];
		return(f(sparse[l][lg], sparse[r - (1 << lg) + 1][lg]));
	}
};


signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		spt A(a);
		for (int i = 0; i < n; i++){
			for (int j = i; j < n; j++){
				cout << "query(" << i << ", " << j << ") = " << A.query(i, j) << endl;
			}
		}
	}
}
