#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
typedef long long ll;
using namespace std;

int timevisited[2001][2001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// ifstream cin("mowing.in");
	 //ofstream cout("mowing.out");
	for (int i = 0; i < 2001; i++){
		for (int j = 0; j < 2001; j++){
			timevisited[i][j] = -1;
		}
	}
	timevisited[1000][1000] = 0;
	pair<int, int> curPos;
	curPos.first = 1000; curPos.second = 1000;
	int n; cin >> n;
	int t = 1;
	int maxX = 1000000000;

	for (int q = 0; q < n; q++){
		char c;
		cin >> c;
		int d; cin >> d;
		if (c == 'E'){
			for (int j = curPos.second + 1; j <= curPos.second + d; j++){
				if (timevisited[curPos.first][j] == -1)
					timevisited[curPos.first][j] = t;
				else
					maxX = min(maxX, t - timevisited[curPos.first][j]);
				t++;
			}
			curPos.second += d;
		}
		else if (c == 'W'){
			for (int j = curPos.second - 1; j >= curPos.second - d; j--){
				if (timevisited[curPos.first][j] == -1)
					timevisited[curPos.first][j] = t;
				else
					maxX = min(maxX, t - timevisited[curPos.first][j]);
				t++;
			}
			curPos.second -= d;
		}
		else if (c == 'N'){
			for (int j = curPos.first - 1; j >= curPos.first - d; j--){
				if (timevisited[j][curPos.second] == -1)
					timevisited[j][curPos.second] = t;
				else
					maxX = min(maxX, t - timevisited[j][curPos.second]);
				t++;
			}
			curPos.first -= d;
		}
		else if (c == 'S'){
			for (int j = curPos.first + 1; j <= curPos.first + d; j++){
				if (timevisited[j][curPos.second] == -1)
					timevisited[j][curPos.second] = t;
				else
					maxX = min(maxX, t - timevisited[j][curPos.second]);
				t++;
			}
			curPos.first += d;
		}
	}
	if (maxX == 1000000000)
		cout << -1 << endl;
	else
		cout << maxX << endl;

	return 0;
}


