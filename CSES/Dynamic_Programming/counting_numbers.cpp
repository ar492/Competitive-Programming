#include<bits/stdc++.h>
using namespace std;
#define int long long

string a, b;

int dp[2][11][20][2];

int f(bool less, int prev, int pos, string lim, bool leadingnonzero){
	int & state = dp[less][prev][pos][leadingnonzero];
	if(state !=- 1) return state;
	if(pos >= (int)lim.length()) return state = 1;
	
	state = 0;
	for(int i = 0; i <= (less ? 9 : lim[pos] - '0'); i ++ ){
		if(i == prev && !(i == 0 && !leadingnonzero)) continue;
		state += f(less || i < lim[pos] - '0', i, pos + 1, lim, leadingnonzero || i);
	}
	return state;
}

void reset(){
	for(int i = 0; i < 2; i ++ )
		for(int j = 0; j < 11; j ++ )
			for(int k = 0; k < 20; k ++ )
				dp[i][j][k][0] = dp[i][j][k][1] =- 1;
}

signed main(){
	reset();
	cin >> a >> b;
	int big = f(0, 10, 0, b, 0);
	reset();
	int small = (stoll(a) == 0 ? 0 : f(0, 10, 0, to_string(stoll(a) - 1), 0));
	cout << (big - small) << endl;	
	
}
