#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int cnt = 0;
	for (int i : {1, 2, 3}){
		for (int j : {1, 2, 3}){
			for (int k : {1, 2, 3}){
				multiset<int> s;
				s.insert(i);
				s.insert(j);
				s.insert(k);
				if (s.count(min({ i, j, k })) > 1){
					cout << i << " " << j << " " << k << endl;
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
}
