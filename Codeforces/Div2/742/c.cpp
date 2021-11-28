#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[11][2][2];
string n;

int dfs(int pos, array < int, 2 > carries){
	if(pos ==- 1)		return carries[0] == 0 && !carries[1];
	int & state = dp[pos][carries[0]][carries[1]];
	if(state !=- 1)	return state;
	char digit = n.at(pos);
	state = 0;
	for(int d1 = 0; d1 <= 9; d1 ++ )
		for(int d2 = 0; d2 <= 9; d2 ++ )
			if(to_string(d1 + d2 + carries[0]).back() == digit)
				state += dfs(pos - 1, {carries[1], (d1 + d2 + carries[0] >= 10)});
	return state;
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t; cin >> t;
	while(t -- ){
		cin >> n;
		for(int i = 0; i < 11; i ++ ) for(int j : {0, 1}) for(int k : {0, 1}) dp[i][j][k] =- 1;
		cout << dfs((int)n.length()-1, {0, 0}) - 2 << endl;
	}
}
