#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

vector<vector<char>> grid; int n,k;

void gravity(){
    vector<char> s;
    for(int i=0; i<10; i++){
        for(int j=0; j<n; j++){
            if(grid[j][i]!='0')
                s.pb(grid[j][i]);
        }
        for(int j=0; j<n-s.size(); j++)
            grid[j][i]='0';
        for(int j=n-s.size(); j<n; j++)
            grid[j][i]=s[j-(n-s.size())];
        s.clear();
    }
}

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
vector<vector<bool>> visited;
int cnt=0;
void clean(int i,int j,char color){
    if(i<0||j<0||i>=n||j>=10||grid[i][j]!=color)return;
    grid[i][j]='0';
    for(int next=0; next<4; ++next) clean(i+dx[next],j+dy[next],color);
}
void ff(int x, int y, char c){
    visited[x][y]=1; cnt++;
    for(int i=0; i<4; i++){
        int xx=x+dx[i]; int yy=y+dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<10 && grid[xx][yy]==c && visited[xx][yy]==0){
            ff(xx, yy, c);
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("mooyomooyo.in"); ofstream cout("mooyomooyo.out");
    cin>>n>>k;
    grid.resize(n, vector<char>(10)); visited.resize(n, vector<bool>(10, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<10; j++)
            cin>>grid[i][j];
    gravity();
    while(true){
        for(int aa=0; aa<n; aa++)
            for(int bb=0; bb<10; bb++)
                visited[aa][bb]=0;
        bool tmp=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                if(grid[i][j]!='0'){
                    ff(i, j, grid[i][j]);
                    if(cnt>=k){
                        tmp=true;
                        clean(i, j, grid[i][j]);
                    }
                    cnt=0;
                }
            }
        }
        if(tmp){gravity();}
        else{break;}
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            cout<<grid[i][j];
        }cout<<endl;
    }
return 0;
}
