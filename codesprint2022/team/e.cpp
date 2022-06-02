#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int mod = 1e9 + 7;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int n; cin >> n;
	string s; cin >> s;
	int bcd = 0, a = 0;
	for (char i : s){
		if (i == 'B' or i == 'C' or i == 'D'){
			bcd++;
		}
		else if (i == 'A') a++;
	}
	

}
