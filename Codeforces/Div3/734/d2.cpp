#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)(X.size())

int n, m, k;

char g[105][105];

char add(char c){ return ((char)(c + 1) == 'z' ? 'a' : (char)(c + 1)); }

void print(){
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << g[i][j] << (j == m - 1 ? "\n" : "");
}

void horiz(int col, int top, int bottom){ // col = left col
	char cur = 'a';
	for (int r = top; r >= bottom; r--){
		for (int i = 0; i < 5; i++){
			if (col > 0 && g[r][col - 1] == cur) cur = add(cur);
			if (r > 0 && cur == g[r - 1][col]) cur = add(cur);
		}
		g[r][col] = g[r][col + 1] = cur;
		cur = add(cur);
	}
}

void vert(int col, int top, int bottom){
	char cur = 'a';
	for (int r = top; r > bottom; r -= 2){
		for (int i = 0; i < 5; i++){
			if (col > 0 && g[r][col - 1] == cur) cur = add(cur);
			if (col > 0 && r - 1 >= 0 && g[r - 1][col - 1] == cur) cur = add(cur);
			if (r - 2 >= 0 && cur == g[r - 2][col]) cur = add(cur);
		}
		g[r][col] = g[r - 1][col] = cur;
		cur = add(cur);
	}
}

void exe2(int h1, int c1, int h2 = 0, int c2 = 0){
	for (int i = 0; i < c1; i++) horiz(2 * i, h1 - 1, 0);
	for (int i = 0; i < 2 * c1; i++) vert(i, n - 1, h1);
	if (h2){
		for (int i = c1; i < c1 + c2; i++) horiz(2 * i, h2 - 1, 0);
		for (int i = 2 * c1; i < 2 * (c1 + c2); i++) vert(i, n - 1, h2);
	}
	for (int i = (h2 ? 2 * (c1 + c2) : 2 * c1); i < m; i++) vert(i, n - 1, 0);
	print();
}

void exe(){
	if (k == 0){
		if (n & 1) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for (int i = 0; i < m; i++) vert(i, n - 1, 0);
			print();
		}
		return;
	}
	for (int h1 = 1; h1 <= n; h1++){
		for (int h2 = 1; h2 <= n; h2++){
			for (int c1 = 1; c1 <= m / 2; c1++){
				int c2 = (k - h1 * c1) / h2;
				if (c1 + c2 <= m / 2 && c2 > 0 && (n - h1) % 2 == 0 && (n - h2) % 2 == 0 && (h1 * c1 + h2 * c2) == k){
					if (n & 1 && m / 2 - (c1 + c2) > 0) break;
					cout << "YES" << endl; exe2(h1, c1, h2, c2);
					return;
				}
				if (c1 <= m / 2 && (n - h1) % 2 == 0 && h1 * c1 == k){
					if (n & 1 && m / 2 - c1 > 0) break;
					cout << "YES" << endl; exe2(h1, c1);
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
}

signed main(){
	int t; cin >> t;
	while (t--){
		for (int i = 0; i < 105; i++) for (int j = 0; j < 105; j++) g[i][j] = ' ';
		cin >> n >> m >> k;
		exe();
	}
}