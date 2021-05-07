#include <bits/stdc++.h>
using namespace std;
//going to be tle
vector<vector<int>> A;
set<int> nv; //not visited
int n,m;

void dfs(int u){//O(n+m)
    nv.erase(u);
    for(int i:A[u])
        if(nv.count(i)) dfs(i);
}
void reset(){
    nv.clear();
    for(int i=0; i<n; i++) nv.insert(i);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    A.resize(n);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        A[u-1].push_back(v-1);
    }
    for(int i=0; i<n; i++){
        reset();
        dfs(i);
        if(!nv.empty()){
            cout<<"NO"<<endl<<i+1<<" "<<*nv.begin()+1<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
return 0;
}
