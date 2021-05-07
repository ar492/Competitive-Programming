#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
signed main(){
        int n,x; cin>>n>>x;
        vector<int> dp(1e6+5, inf);
        vector<int> c(n);
        for(int i=0; i<n; i++) cin>>c[i];
        dp[0]=0;
        for(int i=0; i<=x; i++){
                if(dp[i]==inf) continue;
                for(int coin:c)
                        if(i+coin<=x)
                                dp[i+coin]=min(dp[i+coin], dp[i]+1);
        }
        cout<<(dp[x]==inf ? -1 : dp[x])<<endl;

}

