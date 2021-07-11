#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int black=0, white=0;
vector<int> a[(int)1e5+1];
bool v[(int)1e5+1]; //visited

void dfs(int node, bool c){
    v[node]=1;
    if(c) black++;
    else white++;
    for(int i:a[node])
        if(!v[i]) dfs(i, !c);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        a[u].push_back(v); a[v].push_back(u);
    }
    dfs(1, 0);
    cout<<(ll)black*white-(n-1)<<endl;
return 0;
}
