#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int n, p, x, y; cin >> n >> p >> x >> y;
	int t = 0;
	int cnt = 0;
	for (int i = 1; i <= (int)1e8; i++){
		if (i % n == 0){
			t += y;
		}
		else{
			if (cnt >= p){
				i = (int)(1e9); break;
			}
			t += x;
			cnt++;
		}
	}
	cout << t << endl;
}
