#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int sz = 2e5;
vector<array<int, 4>> rects;
int ids[sz];

bool isect(auto i, auto j){
	for (int x : {1, 2}){
		if (i[2] < j[0] or i[3] < j[1]) return false;
		swap(i, j);
	}
	return true;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int n, t; cin >> n >> t;
	for (int i = 0; i < n; i++){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		rects.pb({ x1, y1, x2, y2 });
	}
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (isect(rects[i], rects[j])){
				if (ids[i] or ids[j]){
					ids[i] = ids[j] = min(ids[i], ids[j]);
				}
				else ids[i] = ids[j] = i;
				cnt++;
			}
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++){
		s.insert(ids[i]);
	}
	int groups = sz(s);
	
	int ans = 2 * cnt + groups + 1;
	
	if (t == 1)
		cout << ans << endl;
	else{
		cout << cnt + 1 << " " << ans - (cnt + 1) << endl;
	}
}
