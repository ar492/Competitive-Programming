#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

const int sz = 200;
char g[sz][sz];
int n, m;

bool in_range(int i, int j){
	if (i >= 0 and j >= 0 and i < n and j < m) return true;
	else return false;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	cin >> n >> m; swap(n, m);
	n++; m++;
	set<array<int, 2>> c;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> g[i][j]; if (g[i][j] == 'C') c.insert({ i, j });
			else if (g[i][j] == 'A') a++;
			else if (g[i][j] == 'B') b++;
		}
	}

	int rmv = 0;
	for (auto p : c){
		for (int dc = -120; dc <= 120; dc++){
			for (int dr = 0; dr <= 120; dr++){
				if (in_range(p[0] + dr, p[1] + dc) and in_range(p[0] - dr, p[1] - dc)){
					if (g[p[0] + dr][p[1] + dc] == 'A' and g[p[0] - dr][p[1] - dc] == 'B'){
						rmv++;
					}
					else if (g[p[0] - dr][p[1] - dc] == 'A' and g[p[0] + dr][p[1] + dc] == 'B'){
						rmv++;
					}
				}
			}
		}
	}
	cout << a * b - rmv << endl;

}