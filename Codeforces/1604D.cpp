#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

bool test(int x, int y, int n){
	return (n % x == y % n);
}
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int x, y; cin >> x >> y;
		if (test(x, y, x + y)){
			cout << (x + y) << endl;
		}
		else if(test(x, y, x)){
			cout << x << endl;
		}
		else{
			cout << (y - (y % x) / 2) << endl;
		}
	}
}