///Solution:
///Divide the grid up into components based on the roads
///For each component (secluded from the rest of the grid by roads)
///.. all of the cows in it will not be able to reach any cows in
///.. any other components without crossing a road
///hence, any pair of cows: from the component and NOT from that component are "distant"
/// so the answer is: SUM iterating over cmpnts(cmp(i)*(total cows-cmp(i)))
///but this doublecnts identical pairs made from cmp(a)->(b) and cmp(b)->(a) so div by 2
#include <bits/stdc++.h>
using namespace std;

struct box{ bool cow; bool l; bool r; bool d; bool u; };

int n,k,r;
vector<vector<box>> grid; vector<vector<bool>> v; //visited
int dx[4]={0, 1, 0, -1}; int dy[4]={1, 0, -1, 0}; //ff
int cnt; // # cows in each connected component
int ans;

void ff(int x, int y){
    v[x][y]=1;
    if(grid[x][y].cow) cnt++;
    for(int i=0; i<4; i++){
        int xx=x+dx[i]; int yy=y+dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<n && !v[xx][yy])
            if((i==0 && grid[x][y].r==0) || (i==1 && grid[x][y].d==0) || (i==2 && grid[x][y].l==0) || (i==3 && grid[x][y].u==0))
                ff(xx, yy);
    }
}

int main(){
    //preliminary stuff
    cin.tie(0)->sync_with_stdio(0);
    freopen("countcross.in","r",stdin); freopen("countcross.out","w",stdout);
    cin>>n>>k>>r;
    grid.resize(n, vector<box>(n, {0, 0, 0, 0, 0}));
    v.resize(n, vector<bool>(n, 0));
    //setting up grid
    for(int i=0; i<r; i++){
        int a,b,c,d; cin>>a>>b>>c>>d; a--; b--; c--; d--;
        if(a>c) swap(a,c); if(b>d) swap(b,d);
        if(a!=c){ grid[a][b].d=1; grid[c][d].u=1; }
        else if(b!=d){ grid[a][b].r=1; grid[c][d].l=1; }
    }
    for(int i=0; i<k; i++){
        int u,v; cin>>u>>v;
        grid[--u][--v].cow=1;
    }
    //floodfill and answer computation
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!v[i][j]){
                ff(i, j); ans+=cnt*(k-cnt); cnt=0;
            }
    cout<<ans/2<<endl;
return 0;
}
