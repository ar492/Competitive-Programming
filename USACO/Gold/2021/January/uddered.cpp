// O(2^n  *  n^2) / large const
#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define nl "\n"
using namespace std;

int n, adj[26][26], dp[1 << 20]; // dp[state] =  cost
const int inf = 1e7;
string s;
char il[20]; // index -> letter

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cin >> s;
	{ // pre stuff
		for (int i = 0; i < len(s) - 1; ++i) ++adj[s[i] - 'a'][s[i + 1] - 'a'];
		set<char> l;
		for (auto i : s) l.insert(i);
		n = sz(l);
		int itr = 0;
		for (char i : l) il[itr++] = i;
		for (auto& i : dp) i = inf;
	}
	for (int msk = 0; msk < (1 << n); ++msk){
		for (short bit = 0; bit < n; ++bit){
			if (!(msk & (1 << bit))){
				int nxt = (msk | (1 << bit)), cst = (dp[msk] == inf ? 1 : dp[msk]);
				for (short i = 0; i < n; i++)
					if (nxt & (1 << i))
						cst += adj[il[bit] - 'a'][il[i] - 'a'];
				dp[nxt] = min(dp[nxt], cst);
			}
		}
	}
	cout << dp[(1 << n) - 1] << nl;
}
