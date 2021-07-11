#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> xlim, ylim, xvec, yvec;
int highest_trit = 39;
int dp[40][3][3][2]; // [pos][ xcarry to pos ][ ycarry to pos ][ suffix of x being formed is leq suffix of xlim ]

namespace util{
	// returns dec->ternary conversion with 0's padded in front to make the length 40
	vector<int> dec_to_ternary(int d){ // approx O(1000)
		string ans = string(40, '0');
		while (d != 0){
			int i = 1, pow = 0;
			while (i * 3 <= d) i *= 3, pow++;
			if (i * 2 <= d) i *= 2, ans[40 - pow - 1] = '2';
			else ans[40 - pow - 1] = '1';
			d -= i;
		}
		vector<int> v;
		for (char c : ans) v.push_back(c - '0');
		return v;
	}
	int carry(int val, int& add){ // this works for sure
		if (val + add < 3){
			int addcpy = add; add = 0;
			return val + addcpy;
		}
		val = (val + add) % 3; add = 1;
		return val;
	}
	void reset(){
		for (int i = 0; i < 40; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 2; l++)
						dp[i][j][k][l] = -1;
	}
}
using namespace util;

int dfs(int pos, int carryX, int carryY, bool leq){ // approx O(1000)
	int cx = carryX, cy = carryY;
	int& state = dp[pos][carryX][carryY][leq];
	if (state != -1) return state; // memoize to ensure each state is done at most once
	state = 0; // going to set it once and for all
	if (pos == highest_trit - 1){ // base case
		if(carryX==0) return(state = leq);
		return state;
	}
	int xpos = carry(xvec[pos], carryX);
	int ypos = carry(yvec[pos], carryY);
	array<int, 2> carries = { carryX, carryY };
	for (int add : {0, 1, 2}){  // setting trits at pos of the (x, y) we are building 
		carryX = carries[0]; carryY = carries[1];
		int addX = add;
		int newxpos = carry(xpos, addX); // new val of x[pos]
		int addY = add;
		int newypos = carry(ypos, addY); // new val of y[pos]
		if (newxpos % 2 != newypos % 2) continue; // if not same parity, ignore and move on
		carryX += addX, carryY += addY;
		state += dfs(pos - 1, carryX, carryY, (newxpos < xlim[pos] || (newxpos == xlim[pos] && leq)));
	}
	return state;
}

signed main(){
	int t; cin >> t;
	while (t--){
		reset(); // fill dp with -1
		int x, y, d; cin >> d >> x >> y;
		if (x < y) swap(x, y); // symmetric, so same result. needed for highest_trit
		xlim = dec_to_ternary(x + d); ylim = dec_to_ternary(y + d);
		xvec = dec_to_ternary(x); yvec = dec_to_ternary(y);
		for (int i = 0; i < xlim.size(); i++){
			if (xlim[i]){
				highest_trit = i; break;
			}
		}
		cout << dfs(39, 0, 0, 1) << endl;
	}
}
