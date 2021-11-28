#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

int f(int a, int b, int c){ // min for a to win amongst b and c
	if (a > b && a > c) return 0;
	return (max(b, c)+1)-a;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int a, b, c; cin >> a >> b >> c;
		cout << f(a, b, c) << " " << f(b, a, c) << " " << f(c, a, b) << endl;
	}
}
