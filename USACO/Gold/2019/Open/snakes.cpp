#include<bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string name) {
	        cin.tie(0)->sync_with_stdio(0);
	        freopen((name+".in").c_str(),"r",stdin);
	        freopen((name+".out").c_str(),"w",stdout);
}

int N,K, a[500], dp[500][500];

signed main(){
        setIO("snakes");
	cin>>N>>K;
	int sum=0;
        for(int i=1; i<=N; i++){
               cin>>a[i]; sum+=a[i];
        }
        int mx=0;
        for(int m=1; m<=N; m++){
                mx=max(mx, a[m]);
                dp[m][0]=mx*m;
                for(int k=1; k<=K; k++){
                        dp[m][k]=2e9;
                        int mx2=a[m];
                        for(int i=m-1; i>=0; i--){
                                dp[m][k]=min(dp[m][k], dp[i][k-1]+mx2*(m-i));
                                mx2=max(mx2, a[i]);
                        }
                }
        }
        cout<<dp[N][K]-sum<<endl;

}

// actually read tips.txt
