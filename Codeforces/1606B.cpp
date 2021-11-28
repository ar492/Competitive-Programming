#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

inline int exe(int n, int k){
	int time = 0;
	int sum = 1;

	for (time; sum <= k; time++, sum *= 2){
		if (sum >= n) return time;
	}
	int m = max(0ll, (n - sum));
	return time + m / k + ((m % k) != 0);
}
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		cout << exe(n, k) << endl;
	}
}
