// https://cses.fi/problemset/task/1667/
#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<"\n"
 
const int sz=1e5+1;
vector<int> adj[sz];
int from[sz];
bool vis[sz];
 
int main(){
	int n,m; cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	queue<int> q;
	q.push(1); // need to get to n
        vis[1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto i:adj[x]){
			if(vis[i]) continue;
			from[i]=x, vis[i]=1, q.push(i);
		}
	}
	if(from[n]==0){
		print("IMPOSSIBLE");
		return 0;
	}
 
	int i=n;
	deque<int> ans={{n}};
	while(i!=1){
		i=from[i]; ans.push_front(i);
	}
	print(ans.size());
	for(int i:ans) print(i);
	return 0;
}
