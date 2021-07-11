/*
	
   	number of integers in range [n, m] with exactly k d digits
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int max_num_digits = 100;
int dp[max_num_digits][max_num_digits][2];
int n, m, k, d;

void reset(){
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
}

int calls = 0;
int f(int c, int x = 0, int y = 0, bool z = 0){ // range [0, c] with state [x][y][z]
	if (dp[x][y][z] != -1){ // memoization
		return dp[x][y][z];
	}
	calls++;
	dp[x][y][z] = (y == k);
	if (x == to_string(c).length()){
		return dp[x][y][z];
	}
	int limit = 9;
	if (!z){ // if the number being formed CAN exceed c
		limit = to_string(c)[x] - '0';
	}
	// now setting the xth digit
	dp[x][y][z] = 0; // going to permanently set dp[x][y][z] now
	for (int xth_digit = 0; xth_digit <= limit; xth_digit++){
		if (z){
			dp[x][y][z] += f(c, x + 1, y + (xth_digit == d), 1);
		}
		else{
			dp[x][y][z] += f(c, x + 1, y + (xth_digit == d), xth_digit < limit);
		}
	}
	return dp[x][y][z];
}

signed main(){
	reset();
	cin >> n >> m >> k >> d;
//	n = 0; m = 5e18, k = 1, d = 5;
	int total = f(m);
	//cout << "total is " << total << endl;
	reset();
	cout << total - f(n - 1) << endl;
	// cout << "calls is " << calls << endl;
}
