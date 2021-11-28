#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;


void exe(int n, int m){
	if (n == 1 and m == 1){
		cout << 0 << endl;
		return;
	}
	if (n == 1 or m == 1){
		cout << 1 << endl;
		return;
	}
	cout << 2 << endl;

}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		exe(n, m);
	}
}
