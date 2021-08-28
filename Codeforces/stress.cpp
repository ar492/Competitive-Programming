
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
			int n = rand(1e8, 1e9);
			int k = rand(1, 10);
			out << n << " " << k << endl;
		}

		
		out.close();
		auto begin = std::chrono::high_resolution_clock::now();

		// code to benchmark


		system("1560F1 < in.txt > out1.txt");
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << "ns for mine" << std::endl;
		//		cout << "done with first " << endl;
		auto begin2 = std::chrono::high_resolution_clock::now();
		system("correct < in.txt > out2.txt");
		auto end2 = std::chrono::high_resolution_clock::now();
		//cout << "done with second" << endl;
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end2-begin2).count() << "ns for correct" << std::endl;
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