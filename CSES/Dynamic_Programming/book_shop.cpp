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

int n, c; // number of items, weight capacity of knapsack
vector<int> weights, values, dp; // dp[i] = at a weight of i, what is maximum value sum
signed main(){_
       cin>>n>>c;
       weights.resize(n);
       values.resize(n);
       for(int &i:weights) cin>>i; for(int &i:values) cin>>i;
       dp.resize(c+1, 0);
       for(int i=0; i<n; i++){
              int v=values[i], w=weights[i];
              for(int j=c; j>=0; j--){
                     if(j+w>c) continue;
                     if(dp[j]!=0 || j==0){
                            dp[j+w]=max(dp[j+w], dp[j]+v);
                     }
              }
       }
	cout << *max_element(dp.begin(), dp.end()) << endl;
}