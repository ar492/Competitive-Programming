#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)(X.size())

signed main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int r = n / 3;
		int r2 = r;
		if(n%3 == 1) r++;
		else if(n%3 == 2) r2++;
		cout << r << " " << r2 << endl;
	}
}
