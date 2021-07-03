/*
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree <
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;

int n, k, t, a[200005];

signed main(){
	cin >> n >> k;
	ordered_set oset;
	for (int i = 0; i < n; i++){
		int u; cin >> u; a[i] = u;
		oset.insert({u, t++});
		if (i >= k){
			oset.erase(oset.lower_bound({a[i - k], 0}));
		}
		if (i >= k - 1){
			cout << (*oset.find_by_order((k - 1) / 2)).first << endl;
		}
	}
}
*/

#include<bits/stdc++.h>
using namespace std;

const int sz = 200005;
int fa[sz], a[sz], bit[sz], n, k;
map<int, int> compressed, decompress;

int psum(int x, int sum = 0){
	for (; x > 0; x -= x & -x) sum += bit[x]; return sum;
}
void add(int x, int val){
	for (; x < sz; x += x & -x) bit[x] += val;
}

signed main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		compressed[a[i]] = 0;
	}
	int index = 1;
	for (auto& i : compressed){
		i.second = index++;
		decompress[i.second] = i.first;
	}
	for (int i = 1; i <= n; i++){
		add(compressed[a[i]], 1);
		if (i >= k + 1) add(compressed[a[i - k]], -1);
		int mid = (k / 2) + (k & 1);
		if (i >= k){
			int lo = 1, hi = 200003, ans = -1;
			while (lo <= hi){
				int m = (lo + hi) / 2;
				if (psum(m) >= mid && psum(m - 1) < mid){
					ans = m; break;
				}
				else if (psum(m) < mid) lo = m + 1;
				else hi = m - 1;
			}
			cout << decompress[ans] << endl;
		}
	}
}