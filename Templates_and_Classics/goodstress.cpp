
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

namespace shuffles{
	template <class T> void shuffle_vector(vector<T>& v){
		shuffle(v.begin(), v.end(), rng);
	}
	template <class T> void shuffle_array(T arr[], int len){
		shuffle(arr, arr + len, rng);
	}
}
using namespace shuffles;

vector<array<int, 2>> tree(int n, int diameter, bool weighted = 0, int lb_weight = 0, int ub_weight = 0){
	int edge_index = 0; vector<array<int, 2>> edges(n - 1);
	for (int i = 1; i <= diameter; ++i) edges.at(edge_index++) = { i, i + 1 }; // placed diameter + 1 nodes [1, diameter+1] .. range for linking is now [2, diameter]
	vector<int> maxd(diameter + 2);
	int rem = n - (diameter + 1);
	for (int i = 1; i <= diameter + 1; ++i) maxd.at(i) = min(i - 1, (diameter + 1) - i); // maxd[i] = maximum # nodes that can be added at i
	vector<vector<int>> depths[n + 1]; // depths[i] contains table of available nodes for each depth .. it is monotonic .. 
	// depth[i][j] cannot exist if depth[i][j-1] does not..
	for (int i = 2; i <= diameter; ++i) depths[i].push_back({ i });
	for (int node = diameter + 2; node <= n; ++node){ // placing node
		int ancestor = rand(2, diameter); // .. under ancestor
		int max_depth = min(maxd.at(ancestor) - 1, sz(depths[ancestor]) - 1);
		int depth = rand(0, max_depth);
		int parent = rand(0, depths[ancestor][depth].size() - 1);
		parent = depths[ancestor][depth][parent];
		edges[edge_index++] = { node, parent };
		if (depths[ancestor].size() == depth + 1) depths[ancestor].push_back({ node });
		else depths[ancestor][depth + 1].emplace_back(node);
	}
	// shuffles and obfuscation
	for (int j = 0; j < 2; ++j){
		int p[n]; for (int i = 0; i < n; ++i) p[i] = i + 1; shuffle_array(p, n);
		for (auto& i : edges){
			i[0] = p[i[0] - 1], i[1] = p[i[1] - 1];
			if (rand(0, 1)) swap(i[0], i[1]);
		}
		shuffle_vector(edges);
	}
	return edges; /*
	if (output_file != "none"){
		ofstream cout(output_file, ios::app);
		cout << n << endl;
		for (auto i : edges) cout << i[0] << " " << i[1] << (weighted ? " " + to_string(rand(lb_weight, ub_weight)) : "") << endl;
	}
	else{
		cout << n << endl;
		for (auto i : edges) cout << i[0] << " " << i[1] << (weighted ? " " + to_string(rand(lb_weight, ub_weight)) : "") << endl;
	}*/
}

bool file_cmp(string file1, string file2){
	ifstream in1(file1); ifstream in2(file2);
	vector<char> input1, input2;
	char c;
	while (in1 >> c) input1.emplace_back(c);
	while (in2 >> c) input2.emplace_back(c);
	if (input1[0] == '1' and input1[1] == '0'){
		/*
		for (auto i : input1) cout << i;
		cout << endl; cout << endl;
		for (auto i : input2) cout << i;
		cout << endl;
		cout << "input1==input2 = " << (input1 == input2) << endl;
		cout << sz(input1) << " " << sz(input2) << endl;*/
	}
	return(input1 == input2);
}

signed main(){
	int T = 0;
	while (1){
		ofstream out("in.txt");
		int lb = 1999;
		int ub = 2 * lb;
		int n = rand(lb, ub);
		// out << n << endl;
		auto edges=tree(n, rand(2*n/3, n));
		out << n << endl;
		for (int i = 0; i < n; i++){
			out << rand(1, 1) << (i == n - 1 ? "\n" : " ");
			//out << max(1ll, rand(n / 100, n / 50)) << (i == n - 1 ? "\n" : " ");
		}
		for (auto i : edges){
			out << i[0] << " " << i[1] << endl;
		}
		out.close();
		//insert generator here

		//ofstream cout("in.txt");

		
		system("faster_dp < in.txt > out1.txt");
		system("faster_dp < in.txt > out2.txt");

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
