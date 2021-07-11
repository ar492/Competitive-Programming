#include <bits/stdc++.h>
using namespace std;
#define TCASES int testcases; cin>>testcases; while(testcases--)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    TCASES{
        int n,m; cin>>n>>m;
        int dp[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char c; cin>>c;
                dp[i][j]=(c=='*');
            }
        }

        int sum=0;
        for(int i=n-2; i>=0; i--){
            for(int j=1; j<m-1; j++){
                if(dp[i][j]==1) dp[i][j]+=min({dp[i+1][j], dp[i+1][j+1], dp[i+1][j-1]});
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) sum+=dp[i][j];
        }
        cout<<sum<<endl;
    }
return 0;
}
