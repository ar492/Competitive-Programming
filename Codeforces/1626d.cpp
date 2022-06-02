// author: ar492
// created: 2022-01-25 18:16:30
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

inline int cp2(int j){ // closest power of 2 geq i
	for (int i = 1; i <= (1 << 18); i <<= 1)
		if (i >= j)
			return i - j;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n), c;
		for (int& i : a) cin >> i;
		sort(all(a));
		int cnt = 1;
		for (int i = 1; i <= n; i++, cnt++)
			if (a[i] != a[i - 1] or i == n)
				c.eb(cnt), cnt = 0;
		n = sz(c);
		for (int i = 1; i < n; i++) c[i] += c[i - 1];
		if (n == 1){
			cout << (2 + cp2(c[0])) << endl;
		}
		else{
			int ans = 1e18;
			auto sum = [&](int i, int j){ return c[j] - (i ? c[i - 1] : 0); }; // [i, j]
			for (int i = 0; i < n; i++){
				for (int j = 1; j <= (1 << 18); j <<= 1){
					int lo = i, hi = n - 1, ind = -1; // include i
					while (lo <= hi){
						int m = lo + hi >> 1;
						if (sum(i, m) > j) ind = m, hi = m - 1;
						else lo = m + 1;
					}
					ind--;
					if (sum(i, n - 1) == j) ind = n - 1;
					//if (ind < i) continue;
					ans = min({ ans, cp2(sum(i, ind)) +
								(i ? cp2(sum(0, i - 1)) : 1) +
								(ind + 1 <= n - 1 ? cp2(sum(ind + 1, n - 1)) : 1) });
				}
			}
			cout << ans << endl;
		}
	}
}
// 1 2 3 8
// 0 1 2 3

// 1 2 3 8
// 0 1 2 3

/*

1
3
1 1 1

1
6
2 2 2 1 1 1

1
4
3 1 2 1

1
1
1


*/