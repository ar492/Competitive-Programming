#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n; cin >> n;
	vector < int > v(n);
	for(int i = 0; i < n; i ++ ){
		cin >> v[i];
	}
	cout << n << endl;
	for(int i : v) cout << i << " ";
}
