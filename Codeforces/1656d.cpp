#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int exe(){
	int n; cin >> n;
	n <<= 1ll;
	for (int k = 2; k <= n; k <<= 1ll){
		if (n % k == 0 and n != k){
			auto doit = [&](int kc){
				int add = n / kc - kc - 1;
				if (add % 2 == 0 and add >= 0) return kc;
				return 0ll;
			};
			if (doit(k)) return k;
			if (doit(n / k)) return n / k;
		}
	}
	return -1;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	while (t--) cout << exe() << endl;
}
