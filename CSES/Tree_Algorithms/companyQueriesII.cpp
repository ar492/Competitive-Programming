//https://sendtoaryansh.gitbook.io/informatics-notes/binary-lifting/binary-lifting-gold-part-2
#include <bits/stdc++.h>
using namespace std;

int n; // number of nodes
const int maxn = 1e6, maxe = log2(maxn) + 5; //maxe = max exponent
vector<int> adj[maxn]; bool vis[maxn]; int depth[maxn]; //for dfs
int up[maxn][maxe]; //up[i][j] is the 2^j ancestor of node i
//the max depth is n if the tree is a single line

void dfs(int node, int p, int d){ //to find all parents of nodes and mark the depths
    up[node][0] = p; // 2^0 ancestor of node = p (parent = p)
    vis[node] = 1;
    depth[node] = d;
    for(int i : adj[node])
        if(!vis[i])
            dfs(i, node, d + 1);
}

int lift(int node, int k){ //kth ancestor of node, found in log(k) (max = log(n)) time
    if(k == 0) return node;
    int gp2 = log2(k);
    if(up[node][gp2] == -1) return -1;
    return(lift(up[node][gp2], k - (1 << gp2)));
}

int lca(int a, int b){ //lowest common ancestor of nodes a and b, found in log(n) time
    a = lift(a, depth[a] - min(depth[a], depth[b]));
    b = lift(b, depth[b] - min(depth[a], depth[b])); //transformation done, now a and b are on same depth
    if(a == b) return a;
    for(int l = maxe - 1; l >= 0; --l)
        if(up[a][l] != up[b][l]) a = up[a][l], b = up[b][l];
    return up[a][0]; //parent of a
}

int main(){
    int n,q; cin>>n>>q;
    for(int i=0; i<n-1; i++){
       int u; cin>>u;
       adj[i+2].push_back(u);
       adj[u].push_back(i+2);
    }
    memset(up, -1, sizeof(up));
    dfs(1, -1, 0);
    for(int l = 1; l < maxe; l++) //dp preprocessing to fill 'up'
        for(int i = 1; i <= n; i++) //nodes 1->n
            if(up[i][l - 1] != -1)
                up[i][l] = up[up[i][l - 1]][l - 1];

       while(q--){
              int u,v; cin>>u>>v;
              cout<<lca(u, v)<<endl;
       }
    return 0;
}

// all integers can be written as sum of powers of 2 - this is used
//the tree is rooted at 1, and is 1-indexed
//the goal is to find LCA(a,b) fast
//the kth ancestor of node u can be found in logn time with binary lifting
//using binary search for LCA, LCA(a, b) can be found in logn * logn time
//but faster way is using 'up'
