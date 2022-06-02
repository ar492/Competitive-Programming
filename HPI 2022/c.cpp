#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int sz = 1e6;
int a[sz], l[sz], r[sz];

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int n; cin >> n;
	assert(n<=sz);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++){
		if (a[i] > a[i - 1]){
			l[i] = l[i - 1] + 1;
		}
	}
	for (int i = n - 2; i >= 0; i--){
		if (a[i] > a[i + 1]){
			r[i] = r[i + 1] + 1;
		}
	}
	int ans = 0; // max(r[0], l[n - 1]);
	for (int i = 1; i < n - 1; i++){
		if (a[i] > a[i - 1] and a[i] > a[i + 1]){
			ans = max(ans, l[i - 1] + r[i + 1] + 3);
		}
	}
	cout << ans << endl;

}
