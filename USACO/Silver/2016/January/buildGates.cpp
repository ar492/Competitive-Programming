#include <bits/stdc++.h>
using namespace std;

const int rmax=2005; const int cmax=2005;
bool grid[rmax][cmax];
bool visited[rmax][cmax];

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
void ff(int r, int c){
    grid[r][c]=1;
    visited[r][c]=1;
    for(int i=0; i<4; i++){
        int rr=r+dx[i]; int cc=c+dy[i];
        if(rr<rmax && cc<cmax && rr>=0 && cc>=0 && !visited[rr][cc] && !grid[rr][cc]){
            visited[rr][cc]=1; ff(rr,cc);
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("gates.in"); ofstream cout("gates.out");
    int n; cin>>n;
    int r=rmax/2; int c=cmax/2; grid[r][c]=1;
    for(int i=0; i<n; i++){
        char cc; cin>>cc;
        if(cc=='N'){grid[r+1][c]=1; grid[r+2][c]=1; r+=2;}
        else if (cc=='S'){ grid[r-1][c]=1; grid[r-2][c]=1; r-=2; }
        else if (cc=='W'){ grid[r][c-1]=1; grid[r][c-2]=1; c-=2; }
        else{ grid[r][c+1]=1; grid[r][c+2]=1; c+=2; }
    }
   // for(int i=0; i<rmax; i++){
    //    for(int j=0; j<cmax; j++){
    //        cout<<grid[i][j];
    //    }cout<<endl;
    //}cout<<endl;
    int cnt=0;
    for(int i=0; i<rmax; i++){
        for(int j=0; j<cmax; j++){
            if(!grid[i][j] && !visited[i][j]){
                cnt++;
                ff(i,j);
            }
        }
    }
    cout<<cnt-1<<endl;
return 0;
}
