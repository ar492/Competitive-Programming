#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int n, ans;

vector < vector<array<int, 2>>> groups;
void compute(){
	int xsum = 0, ysum = 0;
	for (auto i : groups){
		int mxx = 0, y = 0;
		for (auto j : i){
			if (j[0] >= mxx){
				
				mxx = j[0];
				y = max(y, j[1]);
			}
		}
		//cout << "mxx, y: " << mxx << " " << y << endl;
		xsum += mxx;
		ysum += y;
	}
	//cout << "xsum, ysum: " << xsum << " " << ysum << endl;
	ans = max(ans, xsum * xsum + ysum * ysum);
	//cout << "ans is " << ans << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	cin >> n;

	for (int i = 0; i < n; i++){
		int k; cin >> k;
		vector<array<int, 2>> tmp;
		for (int j = 0; j < k; j++){
			array<int, 2> a; cin >> a[0] >> a[1];
			tmp.pb(a);
		}
		groups.pb(tmp);
	}
	compute();
	for (int i = 0; i < n; i++){
		for (auto&j : groups[i]){
			j[0] = -j[0]; j[1] = -j[1];
		}
	}
	compute();
	for (int i = 0; i < n;i++){
		for (auto& j : groups[i]){
			swap(j[0], j[1]);
		}
	}
	compute();
	for (int i = 0; i < n;i++){
		for (auto& j : groups[i]){
			j[0] = -j[0]; j[1] = -j[1];
		}
	}
	compute();

	cout << ans << endl;

}
