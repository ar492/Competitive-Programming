#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t; cin >> t;
	while (t--){
		int s, n; cin >> s >> n;
		for (int i = 0; i < n - 1; i++){
			int mx = 0;
			for (int j = 1;; j *= 10){
				if (s - j >= n - i - 1) mx = j;
				else break;
			}
			s -= mx;
			cout << mx << endl;
		}
		cout << s << endl;
	}
}
