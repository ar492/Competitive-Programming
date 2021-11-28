
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz = 2e5 + 1;
int block = 447;
int a[sz], f[sz * 5];
ll curans, ans[sz], n, q;

struct query{
	int index, l, r;
	bool operator < (query & other) const{
		return make_pair(l / block, r) <
			make_pair(other.l / block, other.r);
	}
};

query queries[sz];

signed main(){
	cin.tie(0) -> sync_with_stdio(0); cin.exceptions(ios_base :: failbit);
	cin >> n >> q;
	block = max((int)sqrt((n*n)/q), 1);
	for (int i = 0; i < n; i ++ )
		cin >> a[i];
	for (int i = 0; i < q; i ++ ){
		queries[i].index = i;
		cin >> queries[i].l >> queries[i].r;
		queries[i].l -- ; queries[i].r -- ;
	}
	sort(queries, queries + q);
	auto add = [ & ](int pos){
		curans += (ll) a[pos] * (2ll * f[a[pos]] + 1);
		++f[a[pos]] ;
	};
	auto rmv = [ & ](int pos){
		curans += (ll) a[pos] * ( - 2ll * f[a[pos]] + 1);
		--f[a[pos]] ;
	};
	int lp = 0, rp = -1;
	for (int i = 0; i < q; i ++ ){
		query & x = queries[i];
		while (lp > x.l) add( -- lp);
		while (rp < x.r) add( ++ rp);
		while (lp < x.l) rmv(lp ++ );
		while (rp > x.r) rmv(rp -- );
		ans[x.index] = curans;
	}
	for (int i = 0; i < q; i ++ )
		cout << ans[i] << endl;
}


