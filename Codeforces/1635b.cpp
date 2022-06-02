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
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		set<int> ismx;
		for (int i = 1; i < n - 1; i++){
			if (a[i - 1]<a[i] and a[i]>a[i + 1]) ismx.insert(i);
		}
		int ans = 0;
		for (int i = 1; i < n - 1; i++){
			if (ismx.count(i - 1) and ismx.count(i + 1)){
				ans++;
				a[i] = max(a[i - 1], a[i + 1]);
				ismx.erase(i - 1);
				ismx.erase(i + 1);
			}
		}
		for (int i = 1; i < n - 1; i++){
			if (ismx.count(i)){
				ans++;
				a[i] = max(a[i - 1], a[i + 1]);
				ismx.erase(i);
			}
		}
		cout << ans << endl;
		for (int i = 0; i < n; i++){
			cout << a[i] << (i == n - 1 ? "\n" : " ");
		}

	}
}
