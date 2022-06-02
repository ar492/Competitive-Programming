#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

struct spt{ // everything 0 - index but 1 - index under the hood so dont worry
	int n;
	vector < int > logs;
	vector < vector < int >> sparse; // 1 - index
	int f(int p1, int p2){ return max(p1, p2); }
	spt(vector < int >& a){ // a is 0 - index
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
		vector < int > a(n), p(n), s(n);
		for (int& i : a) cin >> i;
		for (int i = 0; i < n; i++) p[i] = (i ? p[i - 1] + a[i] : a[0]);
		for (int i = n - 1; ~i; i--) s[i] = (i == n - 1 ? a[n - 1] : s[i + 1] + a[i]);

		spt A(a), P(p), S(s);
		string ans = "YES";
		for (int i = 0; i < n; i++){
			int lp, rp;
			int lo = 0, hi = i;
			while (lo <= hi){
				int m = lo + hi >> 1;
				if (A.query(m, i) != a[i]) lo = m + 1;
				else lp = m, hi = m - 1;
			}
			lo = i, hi = n - 1;
			while (lo <= hi){
				int m = lo + hi >> 1;
				if (A.query(i, m) != a[i]) hi = m - 1;
				else rp = m, lo = m + 1;
			}
			int sum = (P.query(i, rp) - (i ? p[i - 1] : 0)) + (S.query(lp, i) - (i != n - 1 ? s[i + 1] : 0)) - a[i];
			if (sum > a[i]) ans = "NO";
		}
		cout << ans << endl;
	}
}
