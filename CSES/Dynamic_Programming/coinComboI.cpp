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
        dp[0]=1;
        for(int i=0; i<=x; i++){
                if(dp[i]==0) continue;
                for(int coin:c){
                        if(i+coin<=x){
                                dp[i+coin]+=dp[i];
                                dp[i+coin]%=mod;
                        }
                }
        }
        for(int i=0; i<=x; i++) cout<<dp[i]<<" "; cout<<endl;
        cout<<dp[x]<<endl;
}

/*
problem says "distinct" - easier than not

3 10
3 3 4

*/
