#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[10001], a[10001];
signed main(){
       ifstream cin("teamwork.in"); ofstream cout("teamwork.out");
	cin.tie(0)->sync_with_stdio(0);
       int n,k; cin>>n>>k;
       for(int i=1; i<=n; i++){ // 1 - index everything
              cin>>a[i];
       }
       for(int i=1; i<=n; i++){ // i is current index
              int mx=a[i];
              for(int sz=0; sz<k && i-sz-1>=0; sz++){ //adding current i to previous team of size sz
                     mx=max(mx, a[i-sz]);
                    // cout<<"sz, mx: "<<sz<<" "<<mx<<endl;
                     dp[i]=max(dp[i], dp[i-sz-1]+mx*(sz+1));
              }
       }
       cout<<dp[n]<<endl;
}

// actually read tips.txt

/*

5 3
9 9 10 1 1

*/
