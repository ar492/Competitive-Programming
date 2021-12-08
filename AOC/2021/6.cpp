#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	ifstream cin("input.txt");
	string s; getline(cin, s);
	map<int, int> m;
	for (char c : s)
		if (c != ',')
			m[(int)(c - '0')]++;

	int x = 256;
	while (x--){
		int add = 0;
		for (auto& i : m){
			if (i.first == 0){
				add = i.second;
				i.second = 0;
			}
			else{
				m[i.first - 1] += i.second;
				i.second = 0;
			}
		}
		if (add){
			m[8] += add;
			m[6] += add;
		}
	}
	int ans = 0;
	for (auto i : m) ans += i.second;
	cout << ans << endl;
}
