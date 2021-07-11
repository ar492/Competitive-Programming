#ifdef LOCAL
#include<C:\Users\gbpol\Desktop\Useful\Competitive-Programming\Util\cp.h>
#else
#include<bits/extc++.h>
#endif
#define priority_queue std::priority_queue
#define all(X) (X).begin(),(X).end()
#define nl "\n"
#define int long long
#define sz(X) ((int)(X.size()))
using namespace std;

int cnt(string s){
	reverse(s.begin(), s.end());
	int ans = 0;
	int mul = 1;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '1') ans += mul;
		mul *= 2;
	}
	return ans;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		int ans = 0;
		string s; cin >> s;
		vector<int> prev1(s.length(), -1);
		for (int i = 1; i < s.length(); i++){
			prev1[i] = prev1[i - 1];
			if (s[i - 1] == '1') prev1[i] = i - 1;
		}
		for (int i = 0; i < s.length(); i++){
			int j = i;
			while (i - prev1[j] <= 18 && prev1[j] != -1){
				j = prev1[j];
				int x = cnt(s.substr(j, i - j + 1));
				if (i - x + 1 >= 0 && i-x+1>prev1[j]){
					ans++;
				}
			}
		}
		cout << ans + count(s.begin(), s.end(), '1') << endl;
	}
}