#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

int ci(char c){
	return (int)(c - '0');
}


string a, b, s;

bool test(){
	for (char c : b){
		if (c < '0' || c > '9') return 0;
	}
	vector<int> v;
	while (len(a) < len(b)) a = '0' + a;
	while (len(b) < len(a)) b = '0' + b;
	assert(len(a) == len(b));
	for (int i = len(a) - 1; i >= 0; i--){
		v.push_back(ci(a[i]) + ci(b[i]));
	}
	string ans;
	for (auto i : v){
		string x = to_string(i);
		reverse(all(x));
		ans += x;
	}
	while (len(ans) and ans.back() == '0') ans.pop_back();
	reverse(all(ans));
	return ans == s;
}

void exe(int poss, int posa){
	//cout << "poss, posa: " << poss << " " << posa << endl;
	if (poss < 0){
		return;
	}
	if (posa < 0 and poss >= 0){
		for (int i = poss; i >= 0; i--){
			b += s[i];
		}
		return;
	}
	

	for (int i = 0; i < 10; i++){
		if (to_string(ci(a[posa]) + i).back() == s[poss]){
			b += (i + '0');
			
			poss -= (len(to_string(ci(a[posa]) + i)));
			posa--;
			break;
		}
	}
	exe(poss, posa);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	int t; cin >> t;
	while (t--){
		cin >> a >> s;
		exe(len(s) - 1, len(a) - 1);
		reverse(all(b));
		if (test()){
			reverse(all(b));
			while (len(b) and b.back() == '0') b.pop_back();
			reverse(all(b));
			cout << b << endl;
		}
		else cout << -1 << endl;
		//cout << b << endl;
		b.clear();
		
	}
}
