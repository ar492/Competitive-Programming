#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int sz = 2e5+5;
int cnt[sz]; // number of ways to reach each block

int n, m, l, r; // num blocks, num illegal blocks, [l,r]=jump range
bool illegal[sz];

int expo(int a, int b){
	if (a == 0) return b == 0;
	int ans = 1;
	while(b){
		if (b & 1) ans = (ans * a) % mod;
		b >>= 1LL;
		a = (a * a) % mod;
	}
	return ans;
}

int modinv(int a){
	return expo(a, mod - 2);
}

signed main(){
	cnt[1] = 1;
	
	cin >> n >> m >> l >> r;
	for (int i = 0; i < m; i++){
		int j; cin >> j;
		illegal[j] = 1;
		if (j == n){
			cout << 0 << endl; return 0;
		}
	}


	vector<int> psum(sz);
	psum[1] = 1;
	for (int i = 2; i <= n + r - 1; i++){
		cnt[i] = psum[i - 1] - psum[max(i - r - 1, 0ll)];
		if (illegal[i]) cnt[i] = 0;
		if (i > n && i - r <= n) cnt[i] -= cnt[n];
		if (i <= n) psum[i] = psum[i - 1] + cnt[i];
	}
	//for (int i = 0; i <= n + r - 1; i++) cout << cnt[i] << " "; cout << endl;
	//cout << "psum: " << endl;
	//for (int i = 0; i < n + r - 1; i++) cout << psum[i] << " ";cout << endl;
	int bad = 0;
	for (int i = n + 1; i < sz; i++){
		bad += cnt[i];
	}
	/*
	cout << "modinv 2: " << modinv(2) << endl;
	cout << "cnt[n] " << cnt[n] << endl;
	cout << "cnt[n] + bad " << cnt[n] + bad << endl;
*/
	cout << (cnt[n] * modinv(cnt[n] + bad)) % mod << endl;
	
}