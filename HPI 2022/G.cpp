#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int n; cin >> n;
	vector<array<int, 2>> queries;
	vector<int> minr(n), maxl(n);
	for (int i = 0; i < n; i++){
		int pos, len; cin >> pos >> len;
		queries.pb({ pos, len });
		minr[i] = pos + len;
		if (i) minr[i] = min(minr[i], minr[i - 1]);
		maxl[i] = pos;
		if (i) maxl[i] = max(maxl[i], maxl[i - 1]);
	}
	vector<double> sums(n);
	for (int i = n - 1; i >= 0; i--){
		double center = queries[i][0] + queries[i][1] / 2.0;
		sums[i] = center;
		if (i != n - 1) sums[i] += sums[i + 1];
	}
	for (int i = 0; i < n;i++){
		double com = (double)sums[i] / (n - i + 0.0);
		if (com > (double)minr[i] or com < (double)maxl[i]){
			cout << i << endl; return 0;
		}
	}
	cout << -1 << endl;
}
