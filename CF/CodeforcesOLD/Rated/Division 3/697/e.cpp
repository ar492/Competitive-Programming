#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;

int dp[1001][1001];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
        for(int i=0; i<=1000; i++){
                dp[i][i]=1;
                dp[i][0]=1;
        }
        for(int n=1; n<=1000; n++){
                for(int k=1; k<=n; k++){
                        dp[n][k]=(dp[n-1][k-1]+dp[n-1][k])%mod;
                }
        }
        int t; cin>>t;
        while(t--){
                int n,k; cin>>n>>k;
                set<int, greater<int>> input;
                vector<int> f(1001, 0);
                for(int i=0; i<n; i++){
                        int u; cin>>u; input.insert(u);
                        f[u]++;
                }
                int ans=1;
                while(input.size() && k>0){
                        int x=f[*input.begin()]; input.erase(input.begin());
                        ans*=dp[x][min(k, x)];
                        cout<<"*= "<<x<<" choose "<<min(k, x)<<endl;
                        ans%=mod; k-=x;
                }
                cout<<"answer: "<<ans<<endl;
        }
}

/*

1
5 3
4 5 1 4 4

5 4 4 4 1

*/

