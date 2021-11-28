
#include<bits/stdc++.h>
using namespace std;
#define int long long

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
	int cnt = 0;
	while (1){
		ofstream out("in.txt");
		int t = rand(100, 500);
		out << t << endl;
		for (int tc = 0; tc < t; tc++){
			string s;
			for (int i = 0; i < rand(1000, 2000); i++){
				s += (rand(0, 9) + '0');
			}
			out << (int)s.length() << endl << s << endl;
		}
		out.close();

		system("silly < in.txt > out1.txt");
		system("silly.py < in.txt > out2.txt");

              ifstream in1("out1.txt"), in2("out2.txt");
              bool bad=0;

              
              if(!file_cmp("out1.txt", "out2.txt")) bad=true;
              in1.close(); in2.close();
              if (bad){
                     cout << "bad\n";
                     return 0;
		}
		cnt+=t;
		cout << "ok "<<cnt<<endl;
	}
}