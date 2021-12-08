#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int inputsz = 500;

struct pt{int x, y;};
struct line{pt a, b;};

line lines[inputsz];

int grid[1000][1000];

bool diag(line i){
	return abs(i.a.x - i.b.x) == abs(i.a.y - i.b.y);
}

void t2(line a){
	int bigx = a.b.x, smallx = a.a.x;
	int bigy = a.b.y, smally = a.a.y;
	vector<int> xs, ys;
	if (smallx > bigx)
		for (int i = smallx; i >= bigx; i--)
			xs.push_back(i);
	else
		for (int i = smallx; i <= bigx; i++)
			xs.push_back(i);
	if (smally > bigy)
		for (int i = smally; i >= bigy; i--)
			ys.push_back(i);
	else
		for (int i = smally; i <= bigy; i++)
			ys.push_back(i);

	assert(sz(xs) == sz(ys));
	for (int i = 0; i < sz(xs); i++)
		grid[xs[i]][ys[i]]++;
}

void t(line a){
	if (diag(a)){
		t2(a);
		return;
	}
	for (int x = a.a.x; x <= a.b.x; x++)
		for (int y = a.a.y; y <= a.b.y; y++)
			grid[x][y] += 1;

}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	ifstream cin("input.txt");

	for (int i = 0; i < inputsz; i++){
		char trash;
		cin >> lines[i].a.x >> trash >> lines[i].a.y >> trash >> trash >> lines[i].b.x >> trash >> lines[i].b.y;
		if (lines[i].a.x > lines[i].b.x or lines[i].a.y > lines[i].b.y) swap(lines[i].a, lines[i].b);
	}

	for (int i = 0; i < inputsz; i++)
		if (lines[i].a.x == lines[i].b.x or lines[i].a.y == lines[i].b.y or diag(lines[i]))
			t(lines[i]);

	int ans = 0;
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			ans += (grid[i][j] > 1);

	cout << ans << endl;

}
