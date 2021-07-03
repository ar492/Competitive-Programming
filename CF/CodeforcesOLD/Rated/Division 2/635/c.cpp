#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin>>n>>k;
    vector<vector<int>> A(n);
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v; u--; v--;
        A[u].pb(v); A[v].pb(u);
    }
    int tourism=n-k;
    vector<int> t; t.pb(0);//city 0 is tourism
    vector<bool> visited(n, false);//all nodes are un-visited
    queue<int> q;
    q.push(0);//0 is the starting node
    visited[0] = true;
    while (!q.empty() && t.size()<tourism){////do bfs until all nodes are visited
        int u = q.front(); //current node
        cout<<"current node: "<<u<<endl;
        q.pop();
        for (int v:A[u]){//Push all unvisited neighbours of current node into the queue
            if (!visited[v]){
                visited[v] = true;
                t.pb(v);
                q.push(v);
            }
        }
    }
    for(int i=0; i<t.size(); i++){
        cout<<t[i]+1<<" ";
    }
return 0;
}
