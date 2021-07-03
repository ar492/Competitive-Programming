#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+1;
vector<int> adj[sz];
int n, k, ans;
int min_dist[sz], reach_time[sz]; // min_dist[i] is min dist to a leaf for node i, reach_time[i] is min time to reach i from k 
bool vis[sz]; // bfs

signed main(){
	ifstream cin("atlarge.in"); ofstream cout("atlarge.out");
	cin>>n>>k;
	for(int i=0; i<n-1; i++){
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> leaves;
	for(int i=1; i<=n; i++)
		if(adj[i].size()==1)
			leaves.push(i), vis[i]=1;
	while(!leaves.empty()){
		int node=leaves.front();
		leaves.pop();
		for(int i:adj[node]){
			if(vis[i]) continue;
			vis[i]=true;
	      		min_dist[i]=min_dist[node]+1;
			leaves.push(i);
		}
	}
	queue<int> q;	q.push(k);
	fill(vis, vis+sz, false); vis[k]=true;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(int i:adj[node]){
			if(vis[i]) continue;
			if(min_dist[i]<=reach_time[node]+1) ans++;
			else{
				reach_time[i]=reach_time[node]+1;
				vis[i]=true;
				q.push(i);
			}

		}
	}
	cout<<ans<<endl;
}
