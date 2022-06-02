#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define sz(X) ((int)(X.size()))

const ll sz = 500;
ll p[sz][sz];

int countUniqueValues(ll fibNumber) {
	vector<ll> v = { 1, 1 };
	
	for (int i = 2; i < 90; i++) v.emplace_back(v[i - 1] + v[i - 2]);

	for (int i = 0; i < sz; i++) p[0][i] = p[i][0] = 1, p[i][1] = i;
	for (int n = 1; n < sz; n++)
		for (int k = 2; k <= n; k++)
			p[n][k] = p[n - 1][k - 1] + p[n - 1][k];
	int ind = -1;
	for (int i = 0; i < sz(v); i++)
		if (v[i] == fibNumber) ind = i;
	assert(ind != -1);

	map<ll, int> m;
	for (int n = 0; n < sz; n++)
		for (int k = 0; k <= n; k++)
			if (n + k <= ind)
				m[p[n][k]]++;
	int cnt = 0;
	for (auto i : m) if (i.second == 1) cnt++;
	return cnt;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	cout << countUniqueValues(8) << endl;
}
