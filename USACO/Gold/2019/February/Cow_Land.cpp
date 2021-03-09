/*
euler tour technique + BIT and prefix XOR's + some clever observations
*/

#ifdef LOCAL
       #include "C:\\Users\\gbpol\\Desktop\\Useful\\cp.h"
#else
       #include <bits/extc++.h> // #include <bits/stdc++.h>
#endif
using namespace std;
#define time timee
#define __________________________________________________________________________________________________ cin.tie(0)->sync_with_stdio(0);
int n, q;
const int sz = 1e5+4, maxe = 25; //maxe = max exponent
vector<int> adj[sz];
int vals[sz];

namespace BIT{ // this is specifically for xor - inverse of xor is xor
       int bit[sz];
       int pxor(int x, int sum=0){ for(; x>0; x-=x&-x) sum^=bit[x]; return sum; }
       void update(int x, int newval, int oldval=0){ for(; x<sz; x+=x&-x) bit[x]^=(oldval^newval); }
}

namespace ETT{
       int time, ind[sz];
       struct euler{ int node, size, XOR; };
       euler e[sz];
       void dfs(int node, int p=0, int XOR=0){
              XOR^=vals[node];
              int start=time++;
              e[ind[node]=time]={node, -1, XOR};
              for(int i:adj[node]) if(i!=p) dfs(i, node, XOR);
              e[ind[node]].size=time-start;
       }
       void setupEuler(){ dfs(1); }
}

namespace LCA{
       int depth[sz]; //for dfs
       int up[sz][maxe]; //up[i][j] is the 2^j ancestor of node i
       void lcadfs(int node, int p, int d) { //to find all parents of nodes and mark the depths
              up[node][0] = p; // 2^0 ancestor of node = p (parent = p)
              depth[node] = d;
              for(int i : adj[node]) if(i!=p) lcadfs(i, node, d + 1);
       }
       int lift(int node, int k) { //kth ancestor of node, found in log(k) (max = log(n)) time
              if(k == 0) return node;
              int gp2 = log2(k);
              if(up[node][gp2] == -1) return -1;
              return(lift(up[node][gp2], k - (1 << gp2)));
       }
       int lca(int a, int b) { //lowest common ancestor of nodes a and b, found in log(n) time
              a = lift(a, depth[a] - min(depth[a], depth[b]));
              b = lift(b, depth[b] - min(depth[a], depth[b])); //transformation done, now a and b are on same depth
              if(a == b) return a;
              for(int l = maxe - 1; l >= 0; --l)
                     if(up[a][l] != up[b][l]) a = up[a][l], b = up[b][l];
              return up[a][0]; //parent of a
       }
       void setupLCA(){
              memset(up, -1, sizeof(up));
              lcadfs(1, -1, 0);
              for(int l = 1; l < maxe; l++) //dp preprocessing to fill 'up'
                     for(int i = 1; i <= n; i++) //nodes 1->n
                            if(up[i][l - 1] != -1)
                                   up[i][l] = up[up[i][l - 1]][l - 1];
       }
}
using namespace LCA;
using namespace ETT;
using namespace BIT;

signed main(){__________________________________________________________________________________________________
       ifstream cin("cowland.in"); ofstream cout("cowland.out");
       cin>>n>>q;
       for(int i=1; i<=n; i++) cin>>vals[i];
       for(int i = 0; i < n - 1; i++) {
              int u, v; cin >> u >> v;
              adj[u].emplace_back(v); adj[v].emplace_back(u);
       }
       setupLCA(); // nlogn
       setupEuler(); // ~ Cn where C is a constant >2
       while(q--){
              int type, i, j; cin>>type>>i>>j;
              if(type==2) // O(1)
                     cout<<( (e[ind[i]].XOR^pxor(ind[i])) ^ (e[ind[j]].XOR^pxor(ind[j])) ^ (vals[lca(i, j)]) )<<endl;
              else{ // O(logn)
                     update(ind[i], j, vals[i]);
                     update(ind[i]+e[ind[i]].size, j, vals[i]);
                     vals[i]=j;
              }
       }
       // total is large constant * O( (n+q)(logn) + n )
}
