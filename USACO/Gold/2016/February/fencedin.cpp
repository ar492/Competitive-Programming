#include<bits/stdc++.h>
using namespace std;

const int sz=4004002;
namespace DSU{
       int par[sz], size[sz];
       void initialize(){ for(int i=0; i<sz; i++) par[i]=i, size[i]=1; }
       int rep(int v){//finds the representative of a set
              return(v==par[v] ? v : par[v]=rep(par[v]));
       }
       void unite(int a, int b){
              a=rep(a); b=rep(b);
              if (size[a] < size[b]) swap(a, b);
              par[b]=a; size[a]+=size[b];
       }
}
using namespace DSU;

struct edge{
       int u, v, w;
       bool operator<(const edge & other) const{ return w<other.w; } // sort by ascending weights
};

int A,B,n,m, v[2003], h[2003];
edge edges[(int)1e7];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	ifstream cin("fencedin.in");  ofstream cout("fencedin.out");
       cin>>A>>B>>n>>m;

       v[0]=0; v[1]=B; h[0]=0; h[1]=A;
       for(int i=2; i<n+2; i++) cin>>v[i];
       for(int i=2; i<m+2; i++) cin>>h[i];
       sort(v, v+n+2); sort(h, h+m+2);

       int esz=m*(n+1)+n*(m+1);
       // make edges
       int prev=1, where=0;
       for(int i=1; i<n+2; i++, prev+=m+1) // vertical edges
              for(int j=prev; j<prev+m; j++)
                     edges[where++]={j, j+1, v[i]-v[i-1]};
       for(int i=1; i<=(n+1)*(m+1)-(m+1); i++){ // horizontal edges
              int pos=(i%(m+1)); if(!pos) pos=m+1; // if pos = 0, fix it
              edges[where++]={i, i+m+1, h[pos]-h[pos-1]};
       }
       sort(edges, edges+esz);
       // kruskal
       initialize(); // dsu
       long long ans=0;
       for(int i=0; i<esz; i++){
              edge e=edges[i];
              if(rep(e.v)==rep(e.u)) continue;
              unite(e.v, e.u);
              ans+=e.w;
       }
       cout<<ans<<endl;
}
