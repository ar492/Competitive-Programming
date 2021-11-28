#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

bool dp[41][41][41]; // dp[i][j][k] = first i digits, j of them red, residue k when mod by a
array<int, 4> prv[41][41][41];

inline int mod(int a, int b){
	if (a < 0) return (b + (a % b)) % b;
	return a % b;
}

void slv(){
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	vector<int> ma; // mod digits
	int ten = 1;
	for (int i = 1; i <= 45; i++, ten = (ten * 10) % a){
		if (len(s) - i < 0) break;
		int digit = s[len(s) - i] - '0';
		ma.emplace_back((ten * digit) % a);
	}
	reverse(all(ma));
	cout << "modded digits: ";
	for (int i : ma){
		cout << i << " ";
	}cout << endl;
	dp[0][1][ma[0]] = 1;
	for (int i = 1; i < len(s); i++){
		for (int j = 1; j <= i + 1; j++){
			for (int k = 0; k < a; k++){
				auto& cur = dp[i][j][k];
				cur |= dp[i - 1][j][k];
				if (cur){
					prv[i][j][k] = { i - 1, j, k, 1 };
				}
				else{
					cur |= dp[i - 1][j - 1][mod(k - ma[i], a)];
					if (cur){
						prv[i][j][k] = { i - 1, j, k, 0 };
					}
				}
			}
		}
	}
	cout << "DP : \n";
	for (int i = 1; i < len(s); i++){
		for (int j = 1; j <= i + 1; j++){
			for (int k = 0; k < a; k++){
				cout << "DP["<<i<<"]["<<j<<"]["<<k<<"] = "<<dp[i][j][k] << " ";
			}cout << endl;
		}cout << endl;
	}cout << endl;
	int lo = n / 2, hi = lo + 1;
	array<int, 3> ansc = { -1, -1, -1 };
	while (lo >= 1){
		for (int i : {lo, hi}){
			if (dp[len(s) - 1][i][0]){
				cout << "correct for DP[" << len(s) - 1 << "][" << i << "][0]" << endl;
				ansc = { len(s) - 1, lo, 0 };
				lo = 0; break;
			}
		}
		lo--; hi++;
	}
	if (ansc == array<int, 3>{ -1, -1, -1 }){
		cout << "for string with " << s << endl;
		cout << -1 << endl; return;
	}
	cout << ansc[2] << " are red" << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	while (t--){
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 41; i++)
			for (int j = 0; j < 41; j++)
				for (int k = 0; k < 41; k++)
					prv[i][j][k] = { 0, 0, 0 };
		slv();
	}
}
/*

1
5 3 13
02165

*/