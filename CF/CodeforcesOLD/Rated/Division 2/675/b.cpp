#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int g[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) cin>>g[i][j];
        int cost=0;
        for(int i=0; i<(int)(ceil(n/2.0)); i++){
            for(int j=0; j<(int)(ceil(m/2.0)); j++){
                int a[4]={g[i][j], g[i][m-1-j], g[n-1-i][j], g[n-1-i][m-1-j]};
                sort(a, a+4);
                int med=(a[1]+a[2])/2;
                int add=abs(g[i][j]-med)+abs(g[i][m-1-j]-med)+abs(g[n-1-i][j]-med)+abs(g[n-1-i][m-1-j]-med);
                if(i==n-1-i || j==m-1-j) cost+=add/2;
                else cost+=add;

            }
        }
        cout<<cost<<endl;
    }
return 0;
}
/*
1
3 4
1 2 3 4
5 6 7 8
9 10 11 18
*/
