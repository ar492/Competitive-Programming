#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int n, k;

int slv(){
	int u, s; cin >> u >> s;
	int ans = 1e18;
	for (int i : {(u / k)* k, (u / k + 1)* k}){
		ans = min(ans, abs(u - i) + abs(s - i / k));
	}
	return ans;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans += slv();
	}
	cout << ans << endl;
}
