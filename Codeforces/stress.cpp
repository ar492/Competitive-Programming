
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

int32_t main(){
       int T=0;
       while (1){
              cout << "testing " << (T++) << endl;
              ofstream out("in.txt");

		int t = 1e4;
		out << t << endl;
		while (t--){
			int x = rand(2, 1e8) * 2;
			int y = rand(2, 1e8) * 2;
			out << x << " " << y << endl;
		}

		
		out.close();
		auto begin = std::chrono::high_resolution_clock::now();

		// code to benchmark


		system("1604D < in.txt > out1.txt");
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << "ns for mine" << std::endl;

       }
}

/*

testing 0
9069946000ns
testing 1
9164442000ns
testing 2
9551395000ns
testing 3
9434477000ns
testing 4
9681208000ns
testing 5
9696006000ns
testing 6
9872175000ns
testing 7

*/