#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	int x = 1;
	for (int i = 1; i+ (i * i)/2 <= 1e5; i++){
		x = lcm(x, i);
	}
	cout << x << endl;

	int bound = 500;
	for (int a = -bound; a <= bound; a++){
		for (int b = -bound; b <= bound; b++){
			for (int c = -bound; c <= bound; c++){
				if (not a or not b or not c) continue;
				if (a == b + c and b == a + c and c == a + b){
					cout << "a, b, c: " << a << " " << b << " " << c << endl;
				}
			}
		}
	}
}
