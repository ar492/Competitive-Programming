#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int qq=0; qq<t; qq++){
        int n,m; cin>>n>>m;
        char grid[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>grid[i][j];
        int cnt=0;
        for(int i=0; i<m-1; i++)
            if(grid[n-1][i]!='R')
                cnt++;
        for(int i=0; i<n-1; i++)
            if(grid[i][m-1]!='D')
                cnt++;
        cout<<cnt<<endl;

    }
return 0;
}
