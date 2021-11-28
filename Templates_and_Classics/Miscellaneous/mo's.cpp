#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int sz = 2e5 + 1;
const int block = 447;
int n, q, a[sz], freq[sz], ans[sz], curans;
map<int, int> compress;

struct query{
	int index, l, r;
	bool operator<(query& other) const{
		return make_pair(l / block, r) <
			make_pair(other.l / block, other.r);
	}
};

query queries[sz];

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		compress[a[i]] = i;
	}

	for (int i = 0; i < n; i++) a[i] = compress[a[i]];

	for (int i = 0; i < q; i++){
		queries[i].index = i;
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--; queries[i].r--;
	}

	sort(queries, queries + q);

	int lp = 0, rp = -1;

	auto add = [&](int pos){
		++freq[a[pos]];
		if (freq[a[pos]] == 1){
			++curans;
		}
	};	
	auto rmv = [&](int pos){
		--freq[a[pos]];
		curans -= (!freq[a[pos]]);
	};
		
	for (int i = 0; i < q; i++){
		query& x = queries[i];
		while (lp > x.l) add(--lp);
		while (rp < x.r) add(++rp);
		while (lp < x.l) rmv(lp++);
		while (rp > x.r) rmv(rp--);
		ans[x.index] = curans;
	}
	for (int i = 0; i < q; i++){
		cout << ans[i] << endl;
	}
}

