#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;


signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int l;
		cin >> l;
		vector<array<int, 2>> s(l); // [0] is val, [1] is next index, [2] is prev
		set<int> vals[10]; // vals[0] is locations of 0s in s
		for (int i = 0; i < l; i++){
			char c; cin >> c;
			s[i][0] = c - '0';
			vals[s[i][0]].insert(i);
			s[i][1] = -1;
			if (i + 1 < l) s[i][1] = i + 1;
		}
		set<int> done;
		for (int a = 0; a < 10; a++){ // because 90 can result in 01
			for (int i = 0; i <= 9; i++){
				set<int> to_delete;
				for (int j : vals[i]){
					if (s[j][1] == -1 or done.count(j)) continue;
					int nxt = s[s[j][1]][0];
					if (nxt == (s[j][0] + 1) % 10){
						to_delete.insert(j);
						s[j][0] = (s[j][0] + 2) % 10;
						vals[s[j][0]].insert(j);

						done.insert(s[j][1]); // pos of next
						vals[nxt].erase(s[j][1]);
						s[j][1] = s[s[j][1]][1];
					}
				}
				for (int x : to_delete) vals[i].erase(x);
			}
		}

		cout << "Case #" << tc << ": ";
		int i = 0;
		while (i != -1){
			cout << s[i][0];
			i = s[i][1];
		}
		cout << endl;
	}
}