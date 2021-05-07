#include<bits/stdc++.h>
using namespace std;

const int sz=2e5+5;
int n, ans;
vector<int> adj[sz];

int dfs(int node, int par=0){ // return max length to some leaf
       if(adj[node].size()==1 && node!=1) return 0;
       int m1=0, m2=0;
       for(int i:adj[node]){
              if(i!=par){
                     int x=dfs(i, node);
                     if(x+1>m1) m2=m1, m1=x+1;
                     else if(x+1>m2) m2=x+1;
              }
       }
       ans=max(ans, m1+m2);
       return max(m1, m2); // two branches - each goes to a leaf at the bottom
}

int main(){
       cin>>n;
       for(int i=0; i<n-1; i++){
              int u,v; cin>>u>>v;
              adj[u].push_back(v);
              adj[v].push_back(u);
       }
       dfs(1);
       cout<<ans<<endl;
}