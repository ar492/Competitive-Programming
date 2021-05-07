#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

vector<vector<char>> s;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int n,m;

void ff(int x, int y){
    s[x][y]='#';
    for(int i=0; i<4; i++){
        int xx=x+dx[i]; int yy=y+dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<m && s[xx][yy]=='.')
            ff(xx, yy);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    s.resize(n, vector<char>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>s[i][j];

    int cnt=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(s[i][j]=='.')
                {ff(i, j); cnt++;}
    cout<<cnt<<endl;

return 0;
}
