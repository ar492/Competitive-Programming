#include<bits/stdc++.h>
#define ll long long
using namespace std;

signed main(){
        ifstream cin("feast.in"); ofstream cout("feast.out");
	cin.tie(0)->sync_with_stdio(0);
        int t, a, b; cin>>t>>a>>b;
        bool DP[t+1]; // dp[i] = is it possible to have exactly i in the knapsack (i "fullness" in the problem).
        fill(DP, DP+t+1, 0);
        DP[0]=1;
        for(int i=0; i<t; i++){
                if(!DP[i]) continue;
                DP[i/2]=true; // water
                if(i+a<=t) DP[i+a]=true;
                if(i+b<=t) DP[i+b]=true;
        }
        for(int i=0; i<t; i++){
                if(!DP[i]) continue;
                if(i+a<=t) DP[i+a]=true;
                if(i+b<=t) DP[i+b]=true;
        }
        for(int i=t; i>=0; i--){
                if(DP[i]){
                        cout<<i<<endl;
                        return 0;
                }
        }
}

// actually read tips.txt
