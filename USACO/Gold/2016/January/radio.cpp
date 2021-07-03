#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define INF (int)1e18

int n,m,fx,fy,bx,by;
pair<int, int> fjpath[1001], bpath[1001]; // upto 1000 moves
string fj, bessie;
map<char, int> dx={ {'E', 1}, {'W', -1} }, dy={ {'N', 1}, {'S', -1} };

void makepaths(){
     for(int i=0; i<n; i++){
          fjpath[i]={ fx, fy };
          fx+=dx[fj[i]], fy+=dy[fj[i]];
     }
     fjpath[n]={ fx, fy }; //nth step
     for(int i=0; i<m; i++){
          bpath[i]={ bx, by };
          bx+=dx[bessie[i]], by+=dy[bessie[i]];
     }
     bpath[m]={ bx, by }; //mth step
}

int dist(int a, int b){
     return( (fjpath[a].x-bpath[b].x)*(fjpath[a].x-bpath[b].x) +
             (fjpath[a].y-bpath[b].y)*(fjpath[a].y-bpath[b].y) );
}

signed main(){
     ifstream cin("radio.in"); ofstream cout("radio.out");
     cin>>n>>m>>fx>>fy>>bx>>by>>fj>>bessie;
     makepaths();
     int f[1001][1001];
     for(int i=0; i<1001; i++) fill(f[i], f[i]+1001, INF);
     f[0][0]=0;
     f[1][0]=dist(1, 0);
     f[0][1]=dist(0, 1);
     for(int i=2; i<=n; i++) f[i][0]=f[i-1][0]+dist(i, 0); // fill top row
     for(int i=2; i<=m; i++) f[0][i]=f[0][i-1]+dist(0, i); // fill left column
     for(int i=1; i<=n; i++)
          for(int j=1; j<=m; j++)
               f[i][j]=min({f[i-1][j], f[i][j-1], f[i-1][j-1]})+dist(i, j);
     cout<<f[n][m]<<endl;
     return 0;
}


