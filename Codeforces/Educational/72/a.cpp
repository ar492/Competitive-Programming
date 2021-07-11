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

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	int t; cin >> t;
	while (t--){
		int str, inte, exp;
		cin >> str >> inte >> exp;
		int lo = 0, hi = exp, ans = -1;
		while (lo <= hi){
			int x = (lo + hi) / 2;
			if (2 * x > inte + exp - str){
				ans = x; hi = x - 1;
			}
			else{
				lo = x + 1;
			}
		}
		if (ans == -1) cout << 0 << endl;
		else cout << (exp - ans + 1) << endl;
	}
}