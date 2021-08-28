#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;


void io(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);

}

int main(){
	io();
	ll n; cin >> n;
	ll lo = 1, hi = (ll)1e10;
	while (lo <= hi){
		ll m = (lo + hi) / 2;
		ll ans = m - (m / 3 + m / 5 - m / 15);
		if (ans == n && !(m % 3 == 0 || m % 5 == 0)){ cout << m << endl; return 0; }
		else if (ans == n && (m % 3 == 0 || m % 5 == 0)){ hi = m - 1; }
		else if (ans < n) lo = m + 1;
		else hi = m - 1;
	}
	return 0;
}
