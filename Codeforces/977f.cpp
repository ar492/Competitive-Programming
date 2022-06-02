#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(X) (int)((X).size())

const int sz = 2e5 + 5;
int n, a[sz];

// dp[i][0] is len of max conseq subseq with last element = i that has been seen so far
// dp[i][1] is the current index

map < int, array < int, 2 >> dp;

signed main(){
	
	cin >> n;
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	auto upd = [ & ](int val, int newmx, int ind){
		if(newmx > dp[val][0])
			dp[val] = {newmx, ind};
	};
	for(int i = 0; i < n; i ++ )
		upd(a[i], dp[a[i] - 1][0] + 1, i);
	array < int, 2 > mx = {0, - 1};
	for(int i = 0; i < n; i ++ )
		if(dp[a[i]][0] >= mx[0])
			mx = {dp[a[i]][0], i};
	cout << mx[0] << endl;
	vector < int > ans;
	int ind = mx[1], v = a[mx[1]];
	for(int i = ind; i >= 0; i -- ){
		if(sz(ans) == mx[0]) break;
		if(a[i] == v)
			ans.push_back(i + 1), v -- ;
	}
	reverse(begin(ans), end(ans));
	for(int i : ans) cout << i << " ";
}
