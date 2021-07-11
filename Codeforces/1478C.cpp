#include<bits/stdc++.h>
using namespace std;
#define int long long

const int max_num_digits = 20;
int dp[max_num_digits][max_num_digits][2];
int n, m, k;

void reset(){
	for (int i = 0; i < max_num_digits; i++){
		for (int j = 0; j < max_num_digits; j++){
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
}
// x is pos, y is the number of nonzero digits before pos
// z is whether the number being built can't possibly exceed c

int f(int c, int x = 0, int y = 0, bool z = 0){ // range [0, c] with state [x][y][z]
	if (dp[x][y][z] != -1) return dp[x][y][z]; // memoize
	dp[x][y][z] = y <= 3;
	if (x == to_string(c).length()) return dp[x][y][z];
	int limit = 9;
	if (!z) // if the number being formed CAN exceed c
		limit = to_string(c)[x] - '0';
	// now setting the xth digit
	dp[x][y][z] = 0; // going to permanently set dp[x][y][z] now
	for (int xth_digit = 0; xth_digit <= limit; xth_digit++){
		if (z)
			dp[x][y][z] += f(c, x + 1, y + (xth_digit != 0), 1);
		else
			dp[x][y][z] += f(c, x + 1, y + (xth_digit != 0), xth_digit < limit);
	}
	return dp[x][y][z];
}

signed main(){
	int t; cin >> t;
	while (t--){
		reset();
		int l, r; cin >> l >> r;
		int total = f(r);
		reset();
		cout << total - f(l - 1) << endl;
	}
}


