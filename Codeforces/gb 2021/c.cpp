// author: ar492
// created: 2021-12-29 11:05:06
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--){
			for (int j = i; j < n - 1; j++){
				if (a[j] >= a[j - 1]){
					
				}
			}
		}

	}
}
