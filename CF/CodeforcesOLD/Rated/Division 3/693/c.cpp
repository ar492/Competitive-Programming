/*
#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define int long long

void exe(){
     int n; cin>>n;
     vector<int> a(n);
     for(int i=0; i<n; i++) cin>>a[i];
     vector<int> dp=a;
     for(int i=0; i<n; i++){
          if(a[i]+i>=n) continue;
          dp[i+a[i]]=max(dp[i+a[i]], a[i+a[i]]+dp[i]);
     }
     for(int i=0; i<n; i++) cout<<dp[i]<<" "; cout<<endl;
     cout<<*max_element(dp.begin(), dp.end())<<endl;
}
signed main(){
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(ios_base::failbit);
     int t; cin>>t;
     while(t--){
          exe();
     }
     return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define int long long


signed main(){
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(ios_base::failbit);
     int t; cin>>t;
     while(t--){
          int n; cin>>n;
          int v[n];
          for(int i=0; i<n; i++) cin>>v[i];
          sort(v, v+n, greater<int>());
          int a=0;
          int b=0;
          for(int i=0; i<n; i++){
               if(i%2==0 && v[i]%2==0) a+=v[i];
               if(i&1 && v[i]&1) b+=v[i];
          }
          if(a==b) cout<<"Tie"<<endl;
          else  cout<<(a>b ? "Alice" : "Bob")<<endl;

     }
     return 0;
}
