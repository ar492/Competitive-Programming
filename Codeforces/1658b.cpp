#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int mod = 998244353;

int f(int x, int ans = 1){
	for (int i = 1; i <= x; i++){
		ans = (ans * i) % mod;
	}
	return ans;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		if (n & 1) cout << 0 << endl;
		else{
			cout << (f(n / 2) * f(n / 2)) % mod << endl;
		}
	}
}
