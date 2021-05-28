/*

more simple than official sol - correct as well (not ac because weak tests)
want to maximize t/w while having a bare minimum total w
knapsack - same spirit as subset sum
knapsack on the talents - store min weight to make a talent sum of i (to maximize t/w)
O(n* 250*1e3) -> for maxn ~ 6e7 operations

*/

#include<bits/stdc++.h>
#define w first
#define t second
using namespace std;

const int inf=2e9;
int n,w;

signed main(){
    //   ifstream cin("talent.in"); ofstream cout("talent.out");
       cin>>n>>w;
       pair<int, int> cows[n];
       for(int i=0; i<n; i++) cin>>cows[i].w>>cows[i].t;

       vector<int> talent(1e6+10, inf); // talent[i] = min weight to make sum talent of i
       talent[0]=0;
       for(auto cow:cows)
              for(int i=250*1e3; i>=0; i--) // in talent array, 250 * 10^3 is max total talent
                     if(talent[i]!=inf) // if a talent sum of i can be made with some prefix of the cows (not including cur cow)
                            talent[i+cow.t]=min(talent[i+cow.t], talent[i]+cow.w);
       double ans=0;
       for(double t=1; t<talent.size(); t++){ // all talents are positive integers
              if(talent[t] < w) continue;
              if( t / talent[t] > ans) ans = t / talent[t]; //talent : weight ratio
       }
       cout<<(int)(1000*ans)<<endl;
}
