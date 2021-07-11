#include <bits/stdc++.h>
using namespace std;
#define FOR(x,n) for(int x = 0; x < n; x++)

int g[10][10];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--)
    {
        int n,m,ans=0; cin>>n>>m;
        int ncnt=0, zcnt=0;
        int mng=1e9;
        FOR(i, n) FOR(j, m){
            cin>>g[i][j];
            if(g[i][j]<0){ ncnt++; g[i][j]*=-1; }
            mng=min(mng, g[i][j]);
            ans+=g[i][j];
            if(g[i][j]==0) zcnt++;
        }
      //  cout<<"ncount is "<<ncnt<<endl;
       // cout<<"ans is "<<ans<<endl;
        if(zcnt>0 || ncnt%2==0) cout<<ans<<endl;
        else cout<<ans-2*mng<<endl;
    }
return 0;
}
