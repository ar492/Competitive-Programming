#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

inline int mod(int a, int b){
	if (a < 0) return (b + (a % b)) % b;
	return a % b;
}

void s(){
	int n; cin >> n;
	vector < int > a(n);
	map < int, int > freq;
	for(int & i : a){
		cin >> i; freq[i] ++ ;
	}
	for(int & i : a){
		if(freq[i] >= n / 2){
			cout <<- 1 << endl; return;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i ++ ){
		for(int j = i + 1; j < n; j ++ ){
			int x = abs(a[i] - a[j]);
			for(int f = 1; f * f <= x; f ++ ){
				if(x % f == 0){
					auto test = [ & ](int p){
						map < int, int > mp;
						for(int w = 0; w < n; w ++ )
							mp[mod(a[w], p)] ++ ;
						for(auto w : mp)
							if(w.second >= n / 2)
								return true;
						return false;
					};
					if(test(f)) ans = max(ans, f);
					if(test(x / f)) ans = max(ans, x / f);
				}
			}
		}
	}
	cout << ans << endl;
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0); cin.exceptions(ios_base :: failbit);
	int t; cin >> t;
	while (t -- ){
		s();
	}
}
