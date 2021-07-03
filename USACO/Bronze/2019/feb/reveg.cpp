#include <bits/stdc++.h>
using namespace std;

void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("revegetate.in","r",stdin);
    //freopen("revegetate.out","w",stdout);
}

int main(){
    setup();
    int n,m; cin>>n>>m;
    pair<int,int> f[m];
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        if(u>v) swap(u, v);
        f[m]=pair<int, int>(u, v);
    }
    vector<int> a[n+1]; //adj list
    vector<int> colors(n+1, 1);
    for(auto i:f){
        if(colors[i.second]==colors[i.first]){
            int x=1000;
            for(auto j:a[i.second]) x=min(x, j);
            if(x<j){

            }
        }
    }


return 0;
}
