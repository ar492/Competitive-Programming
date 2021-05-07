#include<bits/stdc++.h>
using namespace std;

int n;
const int sz=1e6;
vector<int> adj[sz];
int siz[sz];

void dfs(int node, int par=0){

       siz[node]+=1;
       for(int i:adj[node]){
              if(i==par) continue;
              dfs(i, node);
              siz[node]+=siz[i];
       }
}
int main(){

       cin>>n;
       for(int i=2; i<=n; i++){
              int a; cin>>a;
              adj[i].push_back(a);
              adj[a].push_back(i);
       }       

       dfs(1);
       for(int i=1; i<=n; i++) cout<<siz[i]-1<<endl;

}