#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[50], ns[50]; //vertical of spots, notspots
vector<bool> b(64, 0);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    cin>>n>>m;
    int g[2*n][m];
    for(int i=0; i<2*n; i++)
        for(int j=0; j<m; j++){
            char c; cin>>c;
            if(c=='A') g[i][j]=0;
            else if(c=='T') g[i][j]=1;
            else if(c=='C') g[i][j]=2;
            else g[i][j]=3;
        }
    int cnt=0;
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            for(int k=j+1; k<m; k++){
                bool valid=1;
                for(int l=n; l<2*n; l++)
                    b[ 16*g[l][i]+4*g[l][j]+g[l][k] ]=1;
                for(int l=0; l<n; l++)
                    if(b[ 16*g[l][i]+4*g[l][j]+g[l][k] ]) valid=0;
                for(int l=n; l<2*n; l++)
                    b[ 16*g[l][i]+4*g[l][j]+g[l][k] ]=0;
                if(valid) cnt++;
            }
        }
    }
    cout<<cnt<<endl;
return 0;
}
