#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define int long long


void exe(){

          int n; cin>>n;
          int ones=0, twos=0;
          for(int i=0; i<n; i++){
               int x; cin>>x;
               ones+=(x==1);
               twos+=(x==2);
          }
          if(ones&1 || (ones==0 && twos&1)){
               cout<<"NO"<<endl;
               return;
          }
          else cout<<"YES"<<endl;

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
