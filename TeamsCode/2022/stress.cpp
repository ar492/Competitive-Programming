
#include<bits/stdc++.h>
#define sz(X) ((int)(X.size()))
#define all(X) (X).begin(),(X).end()
#define int long long

using namespace std;

static mt19937
rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){ // [l,r]
	return(uniform_int_distribution<int>(l, r)(rng));
}

bool file_cmp(string file1, string file2){
	ifstream in1(file1); ifstream in2(file2);
	vector<char> input1, input2;
	char c;
	while (in1 >> c) input1.emplace_back(c);
	while (in2 >> c) input2.emplace_back(c);
	return(input1 == input2);
}

signed main(){
	int T = 0;
	while (1){
		ofstream out("in.txt");
		
		//insert generator here
		int n = rand(1, 1000);
		out << n << endl;
		for (int i = 0; i < n; i++){
			out << rand(1, 1e9) << (i == n - 1 ? "\n" : " ");
		}

		out.close();
		system("cards < in.txt > out1.txt");
		system("cards_slow < in.txt > out2.txt");

		ifstream in1("out1.txt"), in2("out2.txt");
		bool bad = 0;

		if (!file_cmp("out1.txt", "out2.txt")) bad = true;

		in1.close(); in2.close();
		if (bad){
			cout << "bad\n";
			return 0;
		}
		else cout << "fine " << T++ << endl;
		

	}
}