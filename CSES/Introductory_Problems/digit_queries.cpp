#include<bits/stdc++.h>
using namespace std;
#define int long long

int q, sz;
int num[20], tens[20] = {1};

signed main(){
	cin >> q;
	int x = 9;
	int ten = 10;
	for(int i = 1; i < 20; i++, ten *= 10, x *= 10, sz = i){
		tens[i] = ten;
		num[i] = x * i + num[i - 1];
		if(num[i] > 1e18) break;
	}

	
	while(q--){
		int u; cin >> u;
		int where;
		for(int i = 1; i <= sz; i++){
			if(num[i] >= u){
				where = i; break;
			}
		}

		char ans;
		int lo = tens[where - 1], hi = tens[where] - 1;
		
		while(lo <= hi){
			int m = lo + hi >> 1;
			int leftpos = (m - tens[where - 1] + 1) * where + num[where - 1] - (where - 1);
			int rightpos = leftpos + where - 1;
			if(u >= leftpos && u <= rightpos){
				ans = to_string(m)[u - leftpos];
				break;
			}
			else if(u < leftpos) hi = m - 1;
			else if(u > rightpos) lo = m + 1;
		}
		cout << ans << endl;

	}
}
