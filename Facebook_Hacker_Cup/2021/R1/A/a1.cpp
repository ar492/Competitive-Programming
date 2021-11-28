
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ifstream cin("weak_typing_chapter_1_input.txt");
	ofstream cout("o.txt");
	int t; cin>>t;
	for(int tc=1; tc<=t; tc++){
		int n; cin>>n;
		string s; cin>>s;
		s=string()+' '+s;
		vector<vector<int>> dp(2, vector<int>(n+2, (int)2e9));
		dp[0][0]=dp[1][0]=0;
		for(int i=1; i<=n; i++){
			if(s[i]!='O'){ // left
				dp[0][i]=min(dp[0][i-1], dp[1][i-1]+1);
			}
			if(s[i]!='X'){ // right
				dp[1][i]=min(dp[1][i-1], dp[0][i-1]+1);
			}
		}
		cout<<"Case #"<<tc<<": "<<min(dp[0][n], dp[1][n])<<endl;
	}
}
