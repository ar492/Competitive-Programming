#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, a, b; cin >> n >> a >> b;
	bool s = 0;
	if(a > b){
		swap(a, b); s = 1;
	}
	int besta = 1e9, bestb = 1e9;
	for(int i = 0; i < 100000; i++){
		int newb = (6 * n) / (a + i);
		newb = max(newb, b);
		if((a + i) * newb < 6 * n) newb++;
		if(besta * bestb > (a + i) * newb){
			besta = a + i;
			bestb = newb;
		}
	}	
	if(s) swap(besta, bestb);
	cout<< besta * bestb << endl << besta << " " << bestb << endl;
}
