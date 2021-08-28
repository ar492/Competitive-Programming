#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(X) (int)((X).size())
#define len(X) (int)((X).length())
#define all(X) (X).begin(), (X).end()

string dtob(int x){
	int b = x;
	string binary = "";
	int mask = 1LL << 32LL;
	while (mask > 0)    {
		binary += (b & mask) ? '1' : '0';
		mask >>= 1LL;
	}
	return binary;
}

int btod(string x){
	int a = 0;
	int tmp = 1;
	reverse(all(x));
	for (int i = 0; i < len(x); i++){
		if (x[i] == '1') a += tmp;
		tmp <<= 1LL;
	}
	return a;
}

signed main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		string strn = dtob(n);
		string strm = dtob(m+1);
		for (int i = 0; i < len(strn); i++){
			if (strm[i] == '1' && strn[i] == '0'){
				string tmp = strm;
				tmp[i] = '0';
				if (btod(tmp) > m) strm[i] = '0';
			}
			if (strn[i] == '1' && strm[i] == '0'){
				strm[i] = '1';
			}
		}
		cout << (btod(strn) ^ btod(strm)) << endl;
	}
}