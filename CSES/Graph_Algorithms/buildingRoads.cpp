#include <bits/stdc++.h>
using namespace std;

int n,m; //nodes, edges
vector<int> a[(int)1e5+1];
vector<int> cmps; //ex. {2, 3, 5} means node 2,3,5 are in dif cmps
bool vis[(int)1e5+1];

void dfs(int node, int index){
    cmps[index]=node;
    vis[node]=1;
    for(int nbr:a[node])
        if(!vis[nbr])
            dfs(nbr, index);
}
int main(){

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int index=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cmps.push_back(-1);
            dfs(i, index);
            index++;
        }
    }
    cout<<cmps.size()-1<<endl;
    for(int i=0; i<cmps.size()-1; i++){
        cout<<cmps[i]<<" "<<cmps[i+1]<<endl;
    }
return 0;
}
