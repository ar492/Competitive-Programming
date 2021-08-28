

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)(X.size())

string exe(int n, int m, int k){
	if (k == 0) return (n&1 ? "NO" : "YES");
	for (int h1 = 1; h1 <= n; h1++){
		for (int h2 = 1; h2 <= n; h2++){
			for (int c1 = 1; c1 <= m / 2; c1++){
				int c2 = (k - h1 * c1) / h2;
				if (c1 + c2 <= m / 2 && c2 > 0 && (n - h1) % 2 == 0 && (n - h2) % 2 == 0 && (h1 * c1 + h2 * c2) == k){
					if (n & 1 && m / 2 - (c1 + c2) > 0) break;
					return "YES";
				}
				if (c1 <= m / 2 && (n - h1) % 2 == 0 && h1 * c1 == k){
					if (n & 1 && m / 2 - c1 > 0) break;
					return "YES";
				}
			}
		}
	}
	return "NO";
}

signed main(){
	int t; cin>>t;
	while(t--){
		int n, m, k; cin>>n>>m>>k;
		cout << exe(n, m, k) << endl;
	}
}