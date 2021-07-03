#include <bits/stdc++.h>
using namespace std;

vector<int> A(100000); //adj list
//each node has exactly 1 departure, possibly more than 1 arrival
//functional graph
vector<bool> v(100000); //visited
int n, ans;
map<int, int> path;

void dfs(int u, int depth){
    path.insert(pair<int, int>(u, depth));
    v[u]=true;
    if(path.count(A[u])){//A[u] is what node u is pointing to
        ans+=depth-path[A[u]]+1; return;
    }
    if(!v[A[u]])
        dfs(A[u], depth+1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    cin>>n;
    A.resize(n); v.resize(n);
    for(int i=0; i<n; i++){
        int ai; cin>>ai; A[i]=ai-1;
    }
    for(int i=0; i<n; i++)
        if(!v[i]){ dfs(i, 1); path.clear(); }
    cout<<ans<<endl;
return 0;
}
