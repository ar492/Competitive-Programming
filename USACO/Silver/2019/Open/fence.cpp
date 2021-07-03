#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

struct cow{
    int x; int y;
};

vector<vector<int>> A;
vector<cow> cows;
vector<int> visited;
int maxX, maxY; int minX=1e9; int minY=1e9; //these are edge/border points for the fence surrounding the moogroup

void dfs(int u){
    maxX=max(maxX, cows[u].x); minX=min(minX, cows[u].x);
    maxY=max(maxY, cows[u].y); minY=min(minY, cows[u].y);
    visited[u]=true;
    for(int i : A[u]){
        if(!visited[i])
            dfs(i);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("fenceplan.in"); ofstream cout("fenceplan.out");
    int n, m; cin>>n>>m;
    A.resize(n); visited.resize(n, false);
    for(int i=0; i<n; i++){
        cow c; cin>>c.x>>c.y; cows.pb(c);
    }
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v; u--; v--;
        A[u].pb(v); A[v].pb(u);
    }
    int res=(int)1e9;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            res=min(res, 2*(maxX-minX+maxY-minY));
            maxX=0; maxY=0; minX=1e9; minY=1e9;
        }
    }
    cout<<res<<endl;
return 0;
}
