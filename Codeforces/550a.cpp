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
	
	string s; cin >> s;
	int n = len(s);
	set<int> a, b;
	for (int i = 0; i < n - 1; i++){
		if (s[i] == 'A' and s[i + 1] == 'B') a.insert(i);
		else if (s[i] == 'B' and s[i + 1] == 'A') b.insert(i);
	}
	string ans = "NO";
	if (sz(a) and sz(b)){
		if ((abs(*a.begin() - (*--b.end())) != 1) or (abs(*b.begin() -(*--a.end())) != 1)){
			ans = "YES";
		}
			
	}
	cout << ans << endl;

}
