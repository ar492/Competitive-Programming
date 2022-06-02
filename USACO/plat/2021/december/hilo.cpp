// observations
// as x goes from k to k+1, there are no LO's after pos[k] (since that's the max LO)
//


#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 2e5 + 5, inf = 1e18;
int n;
int p[sz]; // permutation
int types[sz]; // 1 = hi, -1 = lo
int pos[sz]; // pos[p[i]]=i
int pge[sz]; // prev greater elemtn
int nge[sz]; // next greater element


void pr(){
	for (int i = 0; i < n; i++) cout << types[i] << " "; cout << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	//ifstream cin("input.txt");
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p[i];
		pos[p[i]] = i;
	}

	
	{
		int mh = 1e18;
		for (int i = 0; i < n; i++){
			if (p[i] < mh){
				types[i] = 1;
				mh = p[i];
			}
		}
		
		stack<int> s;
		for (int i = n - 1; i>=0; i--){

			//cout << "sz is " << sz(s) << " and p[" << i << "], s.top(): " << p[i] << " ";
			//if (sz(s)) cout << s.top() << endl;
			//else cout << endl;
			while (sz(s) and p[i] > s.top()){
				//cout << "in here" << endl;
				pge[pos[s.top()]] = p[i];
				s.pop();
			}
			s.push(p[i]);

		}
		s = stack<int>();
		for (int i = 0; i < n; i++){
			while (sz(s) and p[i] > s.top()){
				nge[pos[s.top()]] = p[i];
				s.pop();
			}
			s.push(p[i]);
		}

		for (int i = 0; i < n; i++){
			//cout << "pge of " << i << " is " << pge[i] << endl;
		}
	}

	// next greater element to the left is the new constrictor
	// 
	cout << 0 << endl;
	int ans = 0;
	//pr();
	
	for (int x = 1; x <= n; x++){ // check x and x+1, x goes from hi to lo. x+1 is the new mnhi
		// x goes from hi to lo
		//cout << "at x = " << x << endl;
		if (types[pos[x]] == -2) ans--;
		types[pos[x]] = -1;
		if (x != n and pge[pos[x]] > nge[pos[x]] ){
			types[pos[nge[pos[x]]]] = 1;
		}
		for (int i = pos[x] - 1; i >= 0; i--){
			if (types[i] == -1) break;
			if (types[i] == 1){
				//cout << "adding 1 bcz found a HI at " << i << endl;
				// types[pos[nge[pos[x]]]] = 2;
				types[pos[x]] = -2;
				ans++; break;
			}
		}

		//pr();


		cout << ans << endl;
	}
}
// keep track of previously said word (hi or lo)


// there are no lows to the right of the pivot


// 1 5 3 2

// 
