#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> a[(int)1e5+1];
bool v[(int)1e5+1];

int gp2(int what){
    int x=1;
    int cnt=0;
    while(x<what){
        x*=2;
        cnt++;
    }
    return cnt;
}

void dfs(int node){
    v[node]=1;
    int req=0;
    for(int i:a[node]){
        if(!v[i]){
            ans++;
            req++;
            dfs(i);
        }
    }
    ans+=gp2(req+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    cout<<ans<<endl;

return 0;
}
/*
6
1 2
1 4
2 3
4 5
4 6
*/
