#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int n; cin >> n;
	int r; cin >> r;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	vector<int> p(n + 1);
	for (int i = 0; i < n; i++){
		p[a[i]] = i;
	}
	vector<int> rooms(r);
	for (int& i : rooms) cin >> i;
	int at = 1;
	for (int i : rooms){
		string s = "Right";
		if (p[at] > p[i]){
			s = "Left";
		}
		cout << s << " " << abs(p[at] - p[i]) << endl;
		at = i;
	}


}
