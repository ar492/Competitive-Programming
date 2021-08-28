#include<bits/stdc++.h>
using namespace std;
#define int long long

//set<int> xs, ys;
int n;
vector<array<int, 2>> points;

const double eps = 0;

double getslope(int sx, int sy, int fx, int fy){
	if (fx - sx == 0) return 10686548758764;
	return (fy - sy) / (fx - sx + 0.0);
}

signed main(){
	cin >> n;
	points.resize(n);
	for (int i = 0; i < n; i++){
		cin >> points[i][0] >> points[i][1];
	//	xs.insert(points[i][0]);
	//	ys.insert(points[i][1]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){ // line from points i to points j
			if (i == j) continue;
			int startx = points[i][0];
			int starty = points[i][1];
			int finishx = points[j][0];
			int finishy = points[j][1];
			int cnt = 0;
			for (int k = 0; k < n; k++){
				int curx = points[k][0], cury = points[k][1];
				if (k==i || k==j) cnt++; // endpoints of the line
				else if(abs(getslope(startx, starty, finishx, finishy) - getslope(curx, cury, finishx, finishy)) <= eps) cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	
	cout << ans << endl;
}