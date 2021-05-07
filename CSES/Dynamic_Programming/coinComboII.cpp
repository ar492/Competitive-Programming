#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
const int mod=1e9+7;

signed main(){
       int n,x; cin>>n>>x;
       vector<int> dp(1e6+5, 0);
       vector<int> c(n);
       for(int i=0; i<n; i++){
              cin>>c[i];
       }
       for(int coin:c){
              dp[coin]++;
              for(int i=0; i<=x; i++){
                     if(dp[i]==0) continue;
                     if(i+coin<=x){
                            // cout<<"dp["<<i+coin<<"]"<<endl;
                            dp[i+coin]+=dp[i];
                            dp[i+coin]%=mod;
                     }
              }
              // for(int j=0; j<=x; j++) cout<<dp[j]<<" "; cout<<endl;
       }
       cout<<dp[x]<<endl;
}
