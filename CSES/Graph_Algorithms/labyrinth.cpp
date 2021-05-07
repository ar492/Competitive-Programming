#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

struct item{
    int X; int Y; int D;
};
vector<vector<int>> grid;
vector<vector<bool>> filled;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int n,m;
bool chk=false;

void ff(int x, int y, int cur){
    //cout<<"filled "<<x<<" "<<y<<" is "<<filled[x][y]<<endl;
    queue<item> q;
    q.push({x,y,1});
    filled[x][y]=1;
    while(!q.empty()){
        item it=q.front();
        int x=it.X; int y=it.Y; int d=it.D;
       // cout<<"(x,y)=("<<x<<","<<y<<")"<<endl;
        filled[x][y]=1;
        q.pop();
        for(int i=0; i<4; i++){
            int xx=x+dx[i]; int yy=y+dy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m && (grid[xx][yy]==-2 || grid[xx][yy]==-1) && filled[xx][yy]==0){
                //cout<<xx<<" "<<yy<<endl;
                if(grid[xx][yy]==-1){
                    chk=true;
                    return;
                }
                else
                    {
                        //cout<<"pushing: "<<xx<<", "<<yy<<endl;
                        q.push({xx,yy,d+1}); grid[xx][yy]=d;}
            }
        }
        cur++;
    }
}

string res;
void ff2(int x, int y, string ans){
    int nx, ny; int mnval=1e6;
    char c;
    for(int i=0; i<4; i++){
        int xx=x+dx[i]; int yy=y+dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]>=0){
            if(grid[xx][yy]==0){
                res=ans;
                if(i==0)
                    res=string()+res+'R';
                else if (i==1)
                    res=string()+res+'D';
                else if (i==2)
                    res=string()+res+'L';
                else if (i==3)
                    res=string()+res+'U';
                return;
            }
            if(grid[xx][yy]<mnval){
                nx=xx; ny=yy;
                mnval=grid[xx][yy];
                if(i==0)
                    c='R';
                else if (i==1)
                    c='D';
                else if (i==2)
                    c='L';
                else if (i==3)
                    c='U';
            }
        }
    }
    ff2(nx, ny, (string()+ans+c));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    cin>>n>>m;
    grid.resize(n, vector<int>(m, -3));
    filled.resize(n, vector<bool>(m, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            char c; cin>>c;
            if(c=='A')
                grid[i][j]=0;
            else if (c=='B')
                grid[i][j]=-1;
            else if (c=='.')
                grid[i][j]=-2;
        }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j]==0)
                {ff(i, j, 1); break;}
/*
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==-3)
                cout<<"# ";
            else if(grid[i][j]==-2)
                cout<<". ";
            else if (grid[i][j]==-1)
                cout<<"B ";
            else if (grid[i][j]==0)
                cout<<"A ";
            else if(grid[i][j]>=10)
                cout<<grid[i][j]%10<<" ";
            else
                cout<<grid[i][j]<<" ";
        }cout<<endl;
    }
*/
    if(!chk)
        cout<<"NO"<<endl;
    else{
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==-1)
                    {ff2(i, j, ""); break;}
        reverse(res.begin(), res.end());
        for(int i=0; i<res.length(); i++){
            if(res[i]=='L')
                res[i]='R';
            else if (res[i]=='R')
                res[i]='L';
            else if (res[i]=='U')
                res[i]='D';
            else if (res[i]=='D')
                res[i]='U';
        }
        cout<<"YES"<<endl<<res.length()<<endl<<res<<endl;
    }

return 0;
}
