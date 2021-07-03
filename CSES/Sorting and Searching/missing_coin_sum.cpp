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
	int n; cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		v.push_back(x);
	}
	sort(all(v));
	int sum = 0;
	for (int i = 0; i < n; i++){
		if (sum + 1 < v[i]){
			break;
		}
		else{
			sum += v[i];
		}
	}
	cout << sum + 1 << endl;
}