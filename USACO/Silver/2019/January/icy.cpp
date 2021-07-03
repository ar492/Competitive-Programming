#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

int n; vector<vector<char>> grid;
vector<pair<int,int>> units; //coordinates of blob
int mxarea=0; int mnperi=INF; int cnt=0; //max area, min peri(for max area), num units icecream in blob

void perifind(){
    int tp=0; //temp perimeter of blob
    for(int i=0; i<units.size(); i++){
        int cx=units[i].first; int cy=units[i].second;
        if((cx>0 && grid[cx-1][cy]!='v') || cx==0)//check above
            tp++;
        if((cx<n-1 && grid[cx+1][cy]!='v') || cx==n-1)//check below
            tp++;
        if((cy>0 && grid[cx][cy-1]!='v') || cy==0)//check left
            tp++;
        if((cy<n-1 && grid[cx][cy+1]!='v') || cy==n-1)//check right
            tp++;
    }
    if(mxarea!=cnt){
        mnperi=tp;
        mxarea=cnt;
    }
    else
        mnperi=min(mnperi, tp);
}
void ff(int x, int y){
    grid[x][y]='v'; units.pb(pair<int,int>(x, y)); cnt++;
    for(int i=0; i<4; i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<n && yy<n && xx>=0 && yy>=0 && grid[xx][yy]=='#')
            ff(xx,yy);
    }
}
int main(){
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");
    cin>>n;
    grid.resize(n, vector<char>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(grid[i][j]=='#'){
                ff(i,j);
                if(cnt>=mxarea)
                    perifind();
                units.clear(); cnt=0;
            }
    cout<<mxarea<<" "<<mnperi<<endl;
return 0;
}
