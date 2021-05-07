#include <bits/stdc++.h>
using namespace std;

int cc[(int)1e5+1], n, m;
set<int> a[(int)1e5+1];
bool visited[(int)1e5+1];

void dfs(int node, int cnum){
    visited[node]=1; cc[node]=cnum;
    for(int i:a[node])
        if(!visited[i] && a[i].count(node)) dfs(i, cnum);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        a[u].insert(v); ///directed
    }
    int cnum=1;
    int cctotal=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cctotal++; dfs(i, cnum); cnum++;
        }
    }
    cout<<cctotal<<endl;
    for(int i=1; i<=n; i++) cout<<cc[i]<<" "; cout<<endl;
return 0;
}
