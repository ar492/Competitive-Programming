#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

void exe(vector<int> a, int n){
	if (n % 2 == 0){
		cout << "YES" << endl;
		return;
	}

	for (int i = 0; i < n - 1; i++){
		if (a[i] >= a[i + 1]){
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		exe(a, n);

	}
}
