#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<vector<int>> Gprime;
set<int> nv; //not visited
int n,m;

void dfs(int u, vector<vector<int>> & A){
    nv.erase(u);
    for(int i:A[u])
        if(nv.count(i)) dfs(i, A);
}
void reset(){
    nv.clear();
    for(int i=0; i<n; i++) nv.insert(i);
}
int main(){
    cin>>n>>m;
    G.resize(n); Gprime.resize(n);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        G[u-1].push_back(v-1); Gprime[v-1].push_back(u-1);
    }
    reset(); dfs(0, G);
    if(!nv.empty()){
        cout<<"NO"<<endl<<1<<" "<<*nv.begin()+1<<endl;
        return 0;
    }
    reset(); dfs(0, Gprime);
    if(!nv.empty()){
        cout<<"NO"<<endl<<*nv.begin()+1<<" "<<1<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
return 0;
}
