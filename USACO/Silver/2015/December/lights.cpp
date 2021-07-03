#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

vector<pair<int,int>> a[101][101];
int n,m,cnt;
bool visited[101][101];
bool lit[101][101];

int dx[4]={1, 0, -1, 0};
int dy[4]={0, -1, 0, 1};

bool litneighbor(int x, int y){ //lit but alr visited
    for(int i=0; i<4; i++){
        int xx=x+dx[i]; int yy=y+dy[i];
        if(lit[xx][yy] && visited[xx][yy]) return true;
    }
    return false;
}
void dfs(int x, int y){
    visited[x][y]=1; lit[x][y]=1;
    for(pair<int,int> j : a[x][y]){
        if(!lit[j.F][j.S]){
            lit[j.F][j.S]=1;
            if(litneighbor(j.F, j.S)){
                dfs(j.F, j.S);
            }
        }
    }
    for(int i=0; i<4; i++){
        int xx=x+dx[i]; int yy=y+dy[i];
        if(xx>=1 && yy>=1 && xx<=n && yy<=n && lit[xx][yy] && !visited[xx][yy]){
            dfs(xx,yy);
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("lightson.in"); ofstream cout("lightson.out");
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y,aa,b; cin>>x>>y>>aa>>b;
        a[x][y].pb(pair<int,int>(aa,b));
    }
    dfs(1,1);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cnt+=lit[i][j];
    cout<<cnt<<endl;
return 0;
}
