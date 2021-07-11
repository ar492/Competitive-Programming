#include <bits/stdc++.h>
using namespace std;

char grid[50][50];
int v[50][50];
int dr[4]={0, 1, 0, -1}; int dc[4]={1, 0, -1, 0};
int n, r1, c1, r2, c2;
bool pos=0;
set<pair<int,int>> coords[2];
void ff(int r, int c, int color){
    v[r][c]=1;
    coords[color].insert({r, c});
    if(r==r2 && c==c2) pos=1;
    for(int i=0; i<4; i++){
        int rr=r+dr[i], cc=c+dc[i];
        if(rr<n && cc<n && rr>=0 && cc>=0 && !v[rr][cc] && grid[rr][cc]=='0'){
            ff(rr, cc, color);
        }
    }
}
int main(){
    cin>>n;
    cin>>r1>>c1>>r2>>c2;
    r1--; c1--; r2--; c2--;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    ff(r1, c1, 0); //0 for starting island
    if(pos){
        cout<<0<<endl; return 0;
    }
  //  cout<<"ok"<<endl;
    ff(r2, c2, 1); // 1 for destination island
    int mn=5000;
    for(auto i:coords[0]){
        for(auto j:coords[1]){
            int rs=i.first, rt=j.first, cs=i.second, ct=j.second;
            mn=min(mn, (rs-rt)*(rs-rt)+(cs-ct)*(cs-ct));
        }
    }
    cout<<mn<<endl;
return 0;
}
