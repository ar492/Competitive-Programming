#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<set<int>> A;//adjacency list
int cnt=0;
void dfs(int u){
    visited[u]=true; cnt++;
    for(int i:A[u])
        if(!visited[i])
            dfs(i);
}
void reset(){
    cnt=0;
    fill(visited.begin(), visited.end(), 0);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("closing.in"); ofstream cout("closing.out");
    int n,m; cin>>n>>m;

    visited.resize(n);
    A.resize(n);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v; u--; v--;
        A[u].insert(v); A[v].insert(u);
    }

    set<int> open;
    for(int i=0; i<n; i++) open.insert(i);

    for(int i=0; i<n; i++){
        dfs(*open.begin());
        if(cnt==n-i) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        reset();
        int r; cin>>r; r--; //node to be removed
        open.erase(r);
        A[r].clear();
        for(int j=0; j<n; j++)
            A[j].erase(r);
    }
return 0;
}
/*
dfs multiple times, each time do it on an open (unclosed) barn,
a set of which is maintained so we can choose the i for dfs(i) in O(1) time.
complexity O(n(n+m)) n+m for dfs, n for doing it after n removals/closures of barns
*/
