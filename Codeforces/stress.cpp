/*
#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
       return uniform_int_distribution<int>(l, r)(rng);
}


bool file_cmp(string file1, string file2){
       ifstream in1(file1); ifstream in2(file2);
       vector<char> input1, input2;
       char c;
       while(in1>>c) input1.emplace_back(c);
       while(in2>>c) input2.emplace_back(c);
       return(input1==input2);
}

signed main(){
       int T=0;
       while (1){
              cout << "testing " << (T++) << endl;
              ofstream out("in.txt");

              //insert generator here

		out << 1 << endl;
		int l = rand(1, 5);
		int r = rand(l, l + 5);
		out.close();
              system("1658d < in.txt > out1.txt");
              system("brute < in.txt > out2.txt");

              ifstream in1("out1.txt"), in2("out2.txt");
              bool bad=0;

              
              if(!file_cmp("out1.txt", "out2.txt")) bad=true;
              in1.close(); in2.close();

              if (bad){
                     cout << "bad\n";
                     return 0;
              }
       }
}
*/

#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
       return uniform_int_distribution<int>(l, r)(rng);
}


int exe(int l, int n, vector<int> v){
	n = n - l + 1;
	vector<int> cor(n);
	for (int i = 0; i < n; i++) cor[i] = i + l;
	int ans = 0;
	int cnt = 1;
	for (int i = 0; i < 20; i++){
		int cc = 0, vc = 0;
		for (int& j : cor){
			if (j & 1) cc++;
			j /= 2;
		}
		for (int& j : v){
			if (j & 1) vc++;
			j /= 2;
		}
		if (vc == n - cc){
			ans += cnt;
		}
		cnt *= 2;
	}
	return ans;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);

	while (true){
		int l = rand(1, 500);
		l = 0;
		int r = rand(l, l + 500);
		vector<int> v;
		for (int i = l; i <= r; i++){
			v.eb(i);
		}
		vector<int> vv = v;
		int x = rand(1, 10000);
		for (auto& i : v) i = i ^ x;

		cout << l << " " << r << endl;
		for (auto i : v) cout << i << " "; cout << endl;
		
		assert(vv != v);
		int newx = exe(l, r, v);
		for (auto& i : vv) i ^= newx;
		sort(all(v));
		sort(all(vv));
		if (vv != v){
			cout << "oldx, newx: " << x << " " << newx << endl;
			assert(false);
		}
	}

}

