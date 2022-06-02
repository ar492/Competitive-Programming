// first subtask cheese

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define nl "\n"
#define int long long
using namespace std;

inline int r(int a, int b){ /// getrandom uniform int in [a, b]
	return(((double)rand() / ((int)RAND_MAX + 1)) * (b - a + 1) + a);
}

string s, a = "abcdefghijklmnopqrstuvwxyz";
map<array<char, 2>, int> adj;

int cost(){
	int pos[26];
	for (int i = 0; i <= 25; i++) pos[a[i]-'a'] = i;
	int c = 0;
	for (auto i : adj)
		if (pos[i.first[1]-'a'] <= pos[i.first[0]-'a'])
			c += i.second;
	return c + 1;
}


signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	srand(512534); // deterministic per usaco rules
	cin >> s;
	for (int i = 0; i < len(s) - 1; i++)
		adj[{s[i], s[i + 1]}]++;

	int c = cost();

	for (int tst = 0; tst < 1e5; tst++){
		int i = r(0, 25), j = r(0, 25);
		swap(a[i], a[j]);
		int x = cost();
		if (x < c) c = x;
		else swap(a[i], a[j]);
	}
	cout << c << endl;
}
