#include<bits/stdc++.h>
using namespace std;

const int sz=2e5+5;
int n;
vector<int> adj[sz];
int dist_to_leaf[sz], dist_from_root[sz];
// max dist to leaf


void dfs1(int node, int par=0, int d=0){
	dist_from_root[node]=d;
	for(int i:adj[node]){
		if(i==par) continue;
		dfs1(i, node, d+1);
		dist_to_leaf[node]=max(dist_to_leaf[node], dist_to_leaf[i]+1);
	}
}

void dfs2(int node, int par=0){
	for(int i:adj[node]){
		if(i==par) continue;

	}
}

signed main(){
	cin>>n;
	for(int i=0; i<n-1; i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
}
