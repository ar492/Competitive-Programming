#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;

int g[250][250], n; //input grid, n
//floodfill:
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
bool v[250][250]; int cnt=0; //visited, region sz
bool ffcheck(int xx, int yy){ return(xx>=0 && xx<n && yy>=0 && yy<n && !v[xx][yy]); }
vector<pii> to_delete; set<pii> done; //twoteams()
vector<pair<pii,pii>> edges; //makeEdges()

void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("multimoo.in","r",stdin);
    freopen("multimoo.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin>>g[i][j];
}

void ff(int x, int y, int team, bool twoTeams, int t1, int t2){
    cnt++;
    v[x][y]=true;
    if(twoTeams) to_delete.push_back({x, y});
    for(int i=0; i<4; i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(twoTeams && ffcheck(xx,yy) && (g[xx][yy]==t1 || g[xx][yy]==t2))
            ff(xx, yy, 0, 1, t1, t2);
        if(!twoTeams && ffcheck(xx,yy) && g[xx][yy]==team)
            ff(xx,yy,team, 0, 0, 0);
    }
}

void makeEdges(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(i<n-1) if(g[i+1][j]!=g[i][j]) edges.push_back({{i+1, j}, {i, j}}); //down
            if(j<n-1) if(g[i][j+1]!=g[i][j]) edges.push_back({{i, j+1}, {i, j}}); //right
        }
}

void oneregion(){
    int mxcnt=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!v[i][j]){
                ff(i, j, g[i][j], 0, 0, 0);
                mxcnt=max(cnt, mxcnt);
                cnt=0;
            }
    cout<<mxcnt<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) v[i][j]=0;
}

void reset(){
    for(auto i:to_delete) v[i.F][i.S]=0;
    cnt=0;
    to_delete.clear();
}

void twoteams(){
    int mxcnt=0;
    for(pair<pii, pii> i:edges){
        int id1=g[i.F.F][i.F.S];
        int id2=g[i.S.F][i.S.S];
        if(id1>id2) swap(id1, id2);
        if(!done.count({id1, id2})){
            reset();
            ff(i.F.F, i.F.S, 0, 1, id1, id2);
            mxcnt=max(mxcnt, cnt);
            done.insert({id1, id2});
        }
    }
    cout<<mxcnt<<endl;
}

int main(){
    setup();
    oneregion();
    makeEdges();
    twoteams();
return 0;
}
