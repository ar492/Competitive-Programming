#include <bits/stdc++.h>
using namespace std;

#define int long long

using T = pair<int, int>;
const int sz=1e5+1;
const int INF=1e17;
vector<T> adj[sz], adj2[sz];
int d1[sz]; // dist if source is 1
int dN[sz]; // dist if source is N
int n,m;

void djikstra1(){
    fill(d1, d1 + sz, INF); d1[1] = 0;
    priority_queue<T,vector<T>,greater<T>> bank; //min heap <SP length, node#>
    for(int i = 1; i <= n; i++) bank.push(make_pair(d1[i], i));
    while(!bank.empty()) {
        int dist = bank.top().first, node = bank.top().second;
        bank.pop();
        if(d1[node] != dist) continue;
        for(auto i : adj[node]){
            int dest=i.first, w=i.second;
            if(dist+w<d1[dest]) bank.push(make_pair(d1[dest]=dist+w, dest));
        }
    }
    cout<<"distance from source node = 1: "<<endl;
    for(int i=1; i<=n; i++) cout<<d1[i]<<" "; cout<<endl;
}

void djikstraN(){
    fill(dN, dN + sz, INF); dN[n] = 0;
    priority_queue<T,vector<T>,greater<T>> bank; //min heap <SP length, node#>
    for(int i = 1; i <= n; i++) bank.push(make_pair(dN[i], i));
    while(!bank.empty()) {
        int dist = bank.top().first, node = bank.top().second;
        bank.pop();
        if(dN[node] != dist) continue;
        for(auto i : adj2[node]){
            int dest=i.first, w=i.second;
            if(dist+w<dN[dest]) bank.push(make_pair(dN[dest]=dist+w, dest));
        }
    }
    cout<<"distance from source node = "<<n<<": "<<endl;
    for(int i=1; i<=n; i++) cout<<dN[i]<<" "; cout<<endl;
}
signed main(){

	cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back(make_pair(b, c));
        adj2[b].push_back(make_pair(a, c));
    }
    djikstra1();
    djikstraN();
    int mn=INF;
    for(int a=1; a<=n; a++){
        for(auto edge:adj[a]){
            int A=a;
            int B=edge.first, w=edge.second; // w = weight
            mn=min(mn, d1[A]+w/2LL+dN[B]);
            //cout<<"for A,B: "<<A<<" "<<B<<" considering: "<<d1[A]+w/2+dN[B]<<endl;
        }
    }
    cout<<mn<<endl;


return 0;
}
