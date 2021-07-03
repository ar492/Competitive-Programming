#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ifstream cin("diamond.in"); ofstream cout("diamond.out");
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int mcnt = 0;
	for (int i = 0; i < n - 1; i++){
		int j = i + 1;
		int tcnt = 1;
		while (arr[j] - arr[i] <= k && j < n){
			j++; tcnt++;
		}
		mcnt = max(mcnt, tcnt);
	}
	cout << mcnt << endl;
	return 0;
}
