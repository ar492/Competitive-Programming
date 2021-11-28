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
		string s;
		int l; cin >> l >> s;

		while (true){
			string o = s;
			for (int i = 0; i < len(s) - 1; i++){
				for (int j = 0; j <= 9; j++){

					if (s[i] - '0' != j || len(s)<2) continue;
					
					if ((s[i] - '0' + 1) % 10 == s[i + 1] - '0'){
						s.replace(i, 2, string() + ((char)((s[i] - '0' + 2) % 10 + '0')));
						//cout << s << endl;
						i = -1; break;
					}
				}
			}
			if (s == o) break;
		}
		cout << "Case #" << tc << ": " << s << endl;

		
	}
}
