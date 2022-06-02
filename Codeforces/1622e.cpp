#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

vector<int> cr[10];

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		vector<int> x(n);
		for (int i = 0; i < n; i++) cin >> x[i];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				char c; cin >> c;
				if (c == '1'){
					cr[i].push_back(j);
				}
			}
		}
		vector<int> ans;
		int mx = -1;
		for (int i = 0; i < (1 << n); i++){
			vector<array<int, 2>> f(m);
			for (int i = 0; i < m; i++) f[i][1] = i;
			for (int j = 0; j < n; j++)
				for (int k : cr[j])
					f[k][0] += ((i & (1 << j)) ? 1 : -1);
			
			vector<int> p(m);
			sort(all(f));
			
			for (int j = 0; j < m; j++) p[f[j][1]] = j + 1;
			int sum = 0;
			for (int j = 0; j < n; j++){
				int s = 0;
				for (int k : cr[j]) s += p[k];
				sum += abs(x[j] - s);
			}
			if (sum > mx)
				mx = sum, ans = p;
		}
		for (int i : ans) cout << i << (i == ans.back() ? nl : " ");
		for (int i = 0; i < n; i++) cr[i].clear();
	}
}

/*

1
4 3
5 1 2 2
110
100
101
100

1
1 1
1
1
*/