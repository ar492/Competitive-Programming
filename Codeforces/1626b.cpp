// author: ar492
// created: 2022-01-16 09:37:08
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int c(char i){
	return (int)(i - '0');
}

void exe(){
	string s; cin >> s;
	string fp, sp;
	for (int i = len(s) - 1; i >= 0; i--){
		if (c(s[i]) + c(s[i + 1]) >= 10){
			for (int j = 0; j < i; j++) fp += s[j];
			for (int j = i + 2; j < len(s); j++) sp += s[j];
			fp += (to_string(c(s[i]) + c(s[i + 1])));
			cout << (string() + fp + sp) << endl;
			return;
		}
	}
	string x = to_string(c(s[0]) + c(s[1]));
	for (int i = 2; i < len(s); i++){
		x += s[i];
	}
	cout << x << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	// find largest i such that s[i]+s[i+1] >= 10
	// if none exist, add s[0] and s[1]
	while (t--){
		exe();
	}
}
