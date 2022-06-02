#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;
#define l(X) (--(X).end())
#define f first
#define s second

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n), freq(n + 5);
		for (int& i : a) cin >> i, freq[i]++;
		sort(all(a));
		int cost = 0, ptr=0;
		map<int, int> rem;
		set<int> have;
		for (int i = 0; i <= n; i++){ // [0, i-1] U [i+1, n]
			if (sz(rem) && sz(have) < i){
				have.insert(i - 1);
				freq[(l(rem)->f)]--, freq[i - 1]++;
				cost += (i - 1) - (l(rem)->f);
				if (--(l(rem)->s) == 0)
					rem.erase(l(rem)->f);
			}
			cout << (sz(have) == i ? freq[i] + cost : -1)<<" ";
			if (freq[i] > 1) rem[i] = freq[i] - 1;
			while (ptr < n and a[ptr] <= i) have.insert(a[ptr++]);
		} cout << nl;
	}
}
