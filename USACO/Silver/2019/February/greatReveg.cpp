#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> adj[100001];
bool v[100001];
bool possible=1;
int p[100001]; //parity
int colors[100001];

void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        char j; cin>>j; int u,v; cin>>u>>v;
        int c=(j=='D' ? -1 : 1);
        adj[u].push_back({v,c}); adj[v].push_back({u,c});
    }
}

void dfs(int node, int color){
    v[node]=1;
    colors[node]=color;
    for(auto i:adj[node]){
        if(colors[i.first]!=0 && color*(i.second)!=colors[i.first]){ cout<<0<<endl; exit(0); }
        if(!v[i.first]){
            dfs(i.first, color*i.second);
        }
    }
}

int main(){
    setup();

    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!v[i]){ dfs(i, 1); cnt++; }
    }
    cout<<1<<string(cnt, '0')<<endl;
return 0;
}
