#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

int n;
string s;

int test(set<char> colors){
	int cnt = 0;
	for (int i = 0; i < len(s); i++){
		int oi = i;
		while (i < len(s) && colors.count(s[i])){
			i++;
		}
		if (oi != i){
			cnt++;
			i--;
		}
	}
	return cnt;
}

int exe(){
	return test({ 'O', 'G', 'A', 'Y' }) // yellow
		+ test({ 'O', 'P', 'A', 'R' }) // red
		+ test({ 'P', 'G', 'A', 'B' }) // blue
		;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cin >> n >> s;
		cout << "Case #" << tc << ": " << exe() << endl;

	}
}