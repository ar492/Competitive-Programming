#include<bits/stdc++.h>
using namespace std;

const int sz=2e5+1;
int n;
vector<int> adj[sz];
array<int, 2> dp[sz]; 
// dp[i][0] = max for subtree i if you include node i
// dp[i][1] = max for subtree i if you don't include node i

void dfs(int node, int par=0){
	int isum=0; // sum of included
	for(int i:adj[node]){
		if(i==par) continue;
		dfs(i, node);
		isum+=dp[i][0];
	}
	dp[node][1]=isum;
	for(int i:adj[node]){
		if(i==par) continue;
		dp[node][0]=max(dp[node][0], isum+(1+dp[i][1])-dp[i][0]);
	}
}

signed main(){
	cin>>n;
	for(int i=0; i<n-1; i++){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	dfs(1);
	cout<<max(dp[1][0], dp[1][1])<<endl;
}
