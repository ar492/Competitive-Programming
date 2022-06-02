#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

vector<string> words;
const int sz = 505;
vector<array<int, 2>> adj[sz];
int vis[sz], vis2[sz], dp[sz], in[sz];

set<int> cur;
void dfs(int node){
	cur.insert(node);
	vis[node] = 1;
	for (auto i : adj[node]){
		if (cur.count(i[0]) && in[i[0]] == 1){
			cout << "Shakespeare, who?" << endl;
			exit(0);
		}
		if (vis[i[0]]) continue;
		in[node] = 1;
		dfs(i[0]);
	}
}

deque<int> topo;
void dfs2(int node){
	vis2[node] = 1;
	for (auto i : adj[node]) if (!vis2[i[0]]) dfs2(i[0]);
	topo.push_front(node);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int n; cin >> n;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		words.eb(s);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j) continue;
			string a, b;
			int mx = -1;
			for (int l = 1; l <= min(len(words[i]), len(words[j])); l++){
				a += words[i][l - 1];
				b += words[j][len(words[j]) - l];
				//cout << "a, b: " << a << " " << b << endl;
				string bb = b;
				reverse(all(bb));
				if (a == bb){
					mx = l;
				}
			}
			if (mx != -1){
				adj[j].pb({ i, mx });
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (!vis[i]) dfs(i);
		for (int i : cur) in[i] = 0;
		cur.clear();
	}

	////for (int i = 0; i < n; i++){
	//	cout << i << " -> : ";
	////	for (auto j : adj[i]) cout << j[0] << " "; cout << endl;
	//}

	for (int i = 0; i < n; i++){
		if (!vis2[i]) dfs2(i);
	}

	//cout << "topo:" << endl;
	//for (int i : topo){
	//	cout << i << endl;
	//}
	int ans = 0;
	for (int i = 0; i < sz(topo); i++){
		for (auto j : adj[i]){
			//cout << "dp[" << j[0] << "] = max(" << dp[j[0]] << ", " << dp[i] << " + " << j[1] << ")" << endl;
			dp[j[0]] = max(dp[j[0]], dp[i] + j[1]);
		}
	}
	for (int i = 0; i < n; i++){
		ans = max(ans, dp[i]);
		//cout << "dp[" << i << "] = " << dp[i] << endl;
	}
	cout << ans << endl;


}
