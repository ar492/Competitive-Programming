
#include<bits/stdc++.h>
using namespace std;
#define sz(X) (int)((X).size())

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

namespace shuffles{
       template <class T> void shuffle_vector(vector<T>&v){
              shuffle(v.begin(), v.end(), rng);
       }
       template <class T> void shuffle_array(T arr[], int len){
              shuffle(arr, arr+len, rng);
       }
}
using namespace shuffles;

int32_t main(){
       int T=0;
       while (1){
              cout << "testing " << (T++) << endl;
              ofstream out("in.txt");

		int n = rand(3, 4);
		out << n << endl;
		vector<int> x, y;
		set<int> xs, ys;
		while (sz(xs) < n) xs.insert(rand(0, 7));
		while (sz(ys) < n) ys.insert(rand(0, 7));
		for (int i : xs) x.emplace_back(i);
		for (int i : ys) y.emplace_back(i);
		shuffle_vector(x);
		shuffle_vector(y);
		for (int i = 0; i < n; i++){
			out << x[i] << " " << y[i] << endl;
		}
		out.close();

		system("square < in.txt > out1.txt");
//		cout << "done with first " << endl;
		system("squareac < in.txt > out2.txt");
		//cout << "done with second" << endl;

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