#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz = 5e4 + 1;
map < array < int, 5 > , int > fcnts;
int flavors[sz][5];
int parity[] = {0, 1,  - 1, 1,  - 1, 1};

signed main(){
	cin.tie(0) -  > sync_with_stdio(0);
	ifstream cin("cowpatibility.in"); ofstream cout("cowpatibility.out");	
	ll n; cin >> n;
	for(int i = 0; i < n;++i){
		for(int j = 0; j < 5;++j) cin >> flavors[i][j];
		for(int j = 1; j < 32;++j){
			array < int, 5 > tmp{0};
			for(int k = 0; k < 5;++k)
				if(j & (1 << k))
					tmp[k] = (flavors[i][k]);
			sort(tmp.begin(), tmp.end());
			++fcnts[tmp];
		}
	}
	ll ans = n * (n - 1) / 2;
	for(auto x:fcnts){
		int ss = 5 - count(x.first.begin(), x.first.end(), 0);
		ans -= ((ll)x.second * (x.second - 1) >> 1ll) * (parity[ss]);
	}
	cout << (ans) << endl;
}
