#include <bits/stdc++.h>
using namespace std;
#define INF 1e17
#define int long long

const int sz=1e5+1;
int n,m,k;
vector<pair<int, int>> adj[sz];
vector<int> dist[sz]; // k shortest distances for each node 
bool vis[sz];

void input(){
	cin>>n>>m>>k;
	for(int i=0; i<m; i++){
		int u,v,w; cin>>u>>v>>w;
		adj[u].emplace_back(make_pair(v, w));
	}
}

int32_t main(){
    input();
    using T = pair<int, int>; priority_queue<T,vector<T>,greater<T>> pq; //min heap <kth SP length of some node, node#>
    for(int i=1; i<=n; i++){
        dist[i].resize(k, INF);
    }
	dist[1][0]=0; //min dist from 1 to 1 is 0
    pq.push({0, 1});
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(dist[u][k-1] != d) continue; // what is this
        for(auto e:adj[u]){
            int v=e.first;
            int w=e.second; //weight
            if(dist[v][k-1]>d+w){
                pq.push(make_pair(dist[v][k-1]=d+w, v));
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
    for(int i:dist[n]){
        cout<<i<<endl;
    }
	return 0;
}

//		why does this work
//		first issue: didnt push inf into the pq - and if i did, result is WA
//		second issue : did not cancel calls for redundant leftover edges.. actually did a variant
//		nevermind - second issue resolved - calls are cancelled successfully
