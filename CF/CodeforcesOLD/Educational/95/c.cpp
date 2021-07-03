//Greedy solution
/*
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n; int a[n-1];
        int trash; cin>>trash; n--;
        for(int i=0; i<n; i++) cin>>a[i];
        int i=-1, ans=trash==1;
        while(i+1<n){
            int cnt=0;
            while(i+1<n && a[i+1]==1){ i++; cnt++; }
            ans+=cnt/3;
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/

//DP
#include<bits/stdc++.h>
using namespace std;

const int you=0, frend=1;
int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n; int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        if(n==0){ cout<<a[0]<<endl; }
        else{
            int dp[2][n];
            dp[you][0]=(int)1e9; dp[you][1]=a[0];
            dp[frend][0]=a[0]; dp[frend][1]=a[0]+a[1];

            for(int i=2; i<n; i++){
                dp[frend][i]=min(dp[you][i-1]+a[i], dp[you][i-2]+a[i-1]+a[i]);
                dp[you][i]=min(dp[frend][i-1], dp[frend][i-2]);
            }
            cout<<min(dp[frend][n-1], dp[you][n-1])<<endl;
        }
    }
    return 0;
}
/*
1
8
1 0 1 1 0 1 1 1
*/
