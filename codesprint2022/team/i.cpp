#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

string stop = "22222";
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	string ans = "-----";
	string c;
	for (string s : {"abcde", "fghij", "klmno", "pqrst", "uvwxy"}){
		cout << "? " << s << endl; cout.flush();
		string r; cin >> r;
		if (r == stop) exit(0);
		for (int i = 0; i < 5; i++){
			if (r[i] == '2'){
				ans[i] = s[i];
			}
			if (r[i] != '0'){
				c += s[i];
			}
		}
	}
	if (len(c) == 4) c += 'z';
	assert(len(c) == 5);
	for (int i = 0; i < 4; i++){
		rotate(c.begin(), c.begin() + 1, c.end());
		cout << "? " << c << endl; cout.flush();
		string r; cin >> r;
		if (r == stop) exit(0);
		for (int j = 0; j < 5; j++)
			if (r[j] == '2')
				ans[j] = c[j];
	}
	rotate(c.begin(), c.begin() + 1, c.end());
	for (int i = 0; i < 5; i++){
		if (ans[i] == '-') ans[i] = c[i];
	}
	cout << "? " << ans << endl;


}
