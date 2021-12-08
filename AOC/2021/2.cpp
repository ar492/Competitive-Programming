#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	ifstream cin("input.txt");

	int aim = 0, forward = 0, down = 0;
	while (cin){
		string s; int x; cin >> s >> x;
		if (s == "down"){
			aim += x;
		}
		else if (s == "up"){
			aim -= x;
		}
		else if (s == "forward"){
			forward += x;
			down += aim * x;
		}
	}
	cout << forward * down << endl;

}

