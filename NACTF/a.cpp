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
	vector<int> a(n);
	for (int& i : a) cin >> i;
	int ans = 0;
	for (int i = 1; i < n; i++){
		if (a[i] > a[i - 1]){
			ans += 2 * (a[i] - a[i - 1]);
		}
		else{
			ans += a[i - 1] - a[i];
		}
	}
	cout << ans << endl;
}
