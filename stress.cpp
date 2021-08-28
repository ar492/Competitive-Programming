using namespace std;
#ifdef LOCAL
#include<C:\Users\gbpol\Desktop\Useful\Competitive-Programming\Util\cp.h>
//#include<C:\Users\gbpol\Desktop\Useful\Competitive-Programming\Util\generator.h>
#else
#include<bits/extc++.h>
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v)
{for(int i=0;i<(int)v.size();i++)cout<<v[i]<<(i==(int)v.size()-1?"":" ");return os;}
#endif
#define priority_queue std::priority_queue
#define sz(X) ((int)(X.size()))
#define all(X) (X).begin(),(X).end()
#define _ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
#define nl "\n"
#define long int64_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
       return uniform_int_distribution<int>(l, r)(rng);
}

signed main(){_
       int T=0;
       while (1){
              cout << "testing " << (T++) << endl;
              ofstream out("in.txt");

              //insert generator here
		int n=rand(4, 6);
		int flim=3;
		fout<<n<<" "<<rand(1, flim)<<" "<<rand(1, flim)<<" "<<rand(1, flim)<<" "<<1<<endl;
              out.close();
              system("a < in.txt > out1.txt");
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
