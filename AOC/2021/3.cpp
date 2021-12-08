#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

int z[100], o[100];

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	ifstream cin("input.txt");
	int l = 0;
	string s;
	vector<string> strs;
	while (cin >> s){
		l = len(s);
		for (int i = 0; i < len(s); i++){
			z[i] += (s[i] == '0');
			o[i] += (s[i] == '1');
		}
		strs.push_back(s);
	}
	array<string, 2> ans;
	for (int x : {0, 1}){
		set<string> good(all(strs));
		for (int i = 0; i < l; i++){
			array<int, 2> cnt = { 0, 0 };
			for (string j : good) cnt[j[i] - '0']++;
			if ((cnt[1] >= cnt[0] and !x) or (cnt[1] < cnt[0] and x)){
				for (string s : strs)
					if (s[i] == '0' and good.count(s))
						good.erase(s);
			}
			else
				for (string s : strs)
					if (s[i] == '1' and good.count(s))
						good.erase(s);
			if (sz(good) == 1) break;
		}
		ans[x] = *good.begin();
	}
	bitset<32> g(ans[0]), e(ans[1]);
	cout << e.to_ulong() * g.to_ulong() << endl;
}
