#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	// ifstream cin("records.in"); ofstream cout("records.out");
	int n; cin >> n;
	map<string, int> m;
	for (int qq = 0; qq < n; qq++){
		string arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		string x = arr[0] + ' ' + arr[1] + ' ' + arr[2];
		if (m.count(x))
			m[x]++;
		else
			m.insert(pair<string, int>(x, 1));
	}
	int mx = 0;
	for (auto it = m.begin(); it != m.end(); it++){
		mx = max(it->second, mx);
	}
	cout << mx << endl;
	return 0;
}
