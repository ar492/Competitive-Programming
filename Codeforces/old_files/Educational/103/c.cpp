#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x),end(x)
#define sort(x) sort(all(x))

signed main(){
	cin.tie(0)->sync_with_stdio(0);
        int t; cin>>t;
        while(t--){
                int mx=0;
                int n; cin>>n;
                int a[n+1]={0}, b[n+1]={0}, c[n+1]={0};
                for(int i=0; i<n; i++) cin>>c[i];
                for(int i=0; i<n; i++) cin>>a[i];
                for(int i=0; i<n; i++) cin>>b[i];
                int cur=0, ans=0;
                for(int i=n-1; i>=0; i--){
                        int left=abs(a[i+1]-b[i+1]);
                       // cout<<"left = "<<left<<endl;
                        ans=max(ans, cur+left);
                        if(i==0) continue;
                        if( (cur+c[i]-left-1 < c[i]-1) || (a[i+1]==b[i+1])){ //new chain
                                cur=c[i]-1+2;
                               // cout<<"new chain at "<<i<<", cur = "<<cur<<endl;
                        }
                        else{ // continue
                               // cout<<cur<<" += "<<c[i]<<" - "<<left<<" -1 +2 "<<endl;
                                cur+=c[i]-left-1+2;
                        }
                       // cout<<"cur is "<<cur<<endl;
                        ans=max(ans, cur);
                }
                cout<<"answer: "<<ans<<endl;

        }
}

// actually read tips.txt

/*

1
2
4 3
-1 3
-1 3

*/
