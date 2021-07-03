#ifdef LOCAL
#include<C:\Users\gbpol\Desktop\Useful\Competitive-Programming\Util\cp.h>
#else
#include<bits/extc++.h>
#endif
#define priority_queue std::priority_queue
#define all(X) (X).begin(),(X).end()
#define nl "\n"
#define int long long
#define sz(X) ((int)(X.size()))
#define _ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
       return uniform_int_distribution<int>(l, r)(rng);
}

signed main(){_
       int T=0;
       while (1){
              cout << "testing " << (T++) << endl;
              ofstream out("in.txt");
		int n = rand(1, 1000), x = rand(1, 1e5);
		//insert generator here
		out << n << " " << x << nl;
		for (int i = 0; i < n; i++){
			out << rand(1, 1000) << (i == n - 1 ? nl : " ");
		}
		while (n--){
			out << rand(1, 1000) << (n == 0 ? nl : " ");
		}
		out.close();
              system("book_shop < in.txt > out1.txt");
              system("book_shop_correct < in.txt > out2.txt");

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