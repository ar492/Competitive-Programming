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
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		if (a == b){
			cout << 0 << " " << 0 << endl;
		}
		else{
			int x = b / (b - a);
			int mn = 2e18;
			mn = min(mn, abs(x * (b - a) - b));
			int ans = b - a;
			if (mn > abs((x + 1) * (b - a) - b)){
				mn = abs((x+1) * (b - a) - b);
			}
			cout << ans << " " << mn << endl;
		}
	}
}