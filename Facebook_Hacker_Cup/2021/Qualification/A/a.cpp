#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int inf = 1e18;
signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	//ifstream cin("consistency_chapter_2_input.txt");
	//ofstream cout("o.txt");
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		string s; cin >> s;
		int k; cin >> k;
		vector<vector<int>> adj(26);
		vector<vector<int>> sp(26, vector<int>(26, inf));

		for (int i = 0; i < k; i++){
			char a, b; cin >> a >> b;
			adj[a - 'A'].push_back(b - 'A');
		}
		for (int source = 0; source < 26; source++){
			queue<int> q;
			q.push(source);
			sp[source][source] = 0;
			while (!q.empty()){
				int cur = q.front();
				q.pop();
				for (int i : adj[cur]){
					if (sp[source][i] == inf){
						sp[source][i] = sp[source][cur] + 1;
						q.push(i);
					}
				}
			}
		}

		int ans = inf;
		for (int i = 0; i < 26; i++){
			int tmp = 0;
			bool fine = true;
			for (char c : s){
				tmp += sp[c - 'A'][i];
				if (sp[c - 'A'][i] == inf) fine = 0;
			}
			if (fine) ans = min(ans, tmp);
		}
		cout << "Case #" << tc << ": " << (ans == inf ? -1 : ans) << nl;
	}
}


/*

1
ABC
2
AB
BC

*/