#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define nl "\n"
#define loop(x,n) for(short x = 0; x < n; ++x)
using namespace std;

const int sz = 1001;
int g[sz][sz], b[sz][sz]; // b is building
int n, m;
vector<array<int, 3>> ans;
queue<array<int, 2>> pos;

bool ir(int i, int j){
	if (i >= n - 1 or j >= m - 1 or i < 0 or j < 0) return false;
	return true;
}

int suitable(short i, short j, int color = 0){
	if (not ir(i, j)) return false;
	loop(p, 2)loop(q, 2){
		if (not b[i + p][j + q] and g[i + p][j + q] != b[i + p][j + q]){
			if (color and color != g[i + p][j + q]) return false;
			color = g[i + p][j + q];
		}
	}
	return color;
}

void c(short i, short j){ // from top left
	int color = suitable(i, j);
	if (not color) return;
	ans.pb({ i + 1, j + 1, color });
	loop(p, 2)loop(q, 2)
		if (not b[i + p][j + q])
			b[i + p][j + q] = color;
	for (short p : {0, -1, 1})
		for (short q : {0, -1, 1})
			if (suitable(i + p, j + q))
				pos.push({ i + p, j + q });
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cin >> n >> m;
	ans.reserve(n * m);
	loop(i, n)loop(j, m) cin >> g[i][j];
	loop(i, n - 1)loop(j, m - 1)
		if (g[i][j] == g[i + 1][j] and g[i][j] == g[i][j + 1] and g[i][j] == g[i + 1][j + 1])
			pos.push({ i, j });
	while (sz(pos)){
		auto f = pos.front();
		pos.pop();
		c(f[0], f[1]);
	}
	loop(i, n)loop(j, m) if (not b[i][j]){
		cout << -1 << nl; return 0;
	}
	cout << sz(ans) << nl;
	for (int i = sz(ans) - 1; ~i; i--) cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << nl;
}
