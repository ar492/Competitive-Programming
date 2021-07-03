#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x),end(x)
#define sort(x) sort(all(x))

int n,k;
bool ok(int m){
        int sum=m*n;
        int mul=k*((m*n)/k);
      //  cout<<"sum: "<<sum<<", mul: "<<mul<<endl;
     //   cout<<"returning "<<(sum>=k && sum-(sum-mul)>=n)<<" for "<<m<<endl;
        return(sum>=k && sum-(sum-mul)>=n);
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
        int t; cin>>t;
        while(t--){
                cin>>n>>k;
                int lo=1, hi=1e9+1, ans;
                while(lo<=hi){
                        int m=(lo+hi)/2;
                        if(ok(m)){
                                ans=m, hi=m-1;
                        }
                        else lo=m+1;
                }
                cout<<ans<<endl;
        }
}

// actually read tips.txt
