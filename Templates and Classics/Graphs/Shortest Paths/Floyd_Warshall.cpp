// https://cses.fi/problemset/task/1672
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e17
// all pairs shortest path problem (APSP)

int adj[501][501];
int d[501][501];
signed main(){
     cin.tie(0)->sync_with_stdio(0);
     for(int i=0; i<501; i++)
          for(int j=0; j<501; j++)
               adj[i][j]=d[i][j]=INF;
     int n,m,q; cin>>n>>m>>q;
     for(int i=0; i<m; i++){
          int a,b,c;
          cin>>a>>b>>c;
          adj[a][b]=adj[b][a]=min(adj[a][b], c);
     }
     for(int i=1; i<=n; i++){
          for(int j=1; j<=n; j++){
               if(i==j) d[i][j]=0;
               else if(adj[i][j]!=INF) d[i][j]=adj[i][j];
               else d[i][j]=INF;
          }
     }

     for(int k=1; k<=n; k++) // intermediate
          for(int i=1; i<=n; i++) // source
               for(int j=1; j<=n; j++) // destination
                    d[i][j]=min(d[i][j], d[i][k]+d[k][j]);

     for(int i=0; i<q; i++){
          int a,b; cin>>a>>b;
          cout<<(d[a][b]==INF ? -1 : d[a][b])<<endl;
     }
     return 0;
}
