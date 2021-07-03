#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a[(int)1e5+1];
bool v[(int)1e5+1];
string s;

int cc[(int)1e5+1];

void dfs(int node, int cmp){
    v[node]=1; cc[node]=cmp;
    for(int adj:a[node])
        if(!v[adj] && s[adj]==s[node]) dfs(adj, cmp);
}

void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin>>n>>m;
    s=" "; string temp; cin>>temp; s+=temp;
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        a[u].push_back(v); a[v].push_back(u);
    }
}

void queries(){
    for(int i=0; i<m; i++){
        int u,v; char c; cin>>u>>v>>c;
        if(cc[u]!=cc[v] || (cc[u]==cc[v] && s[u]==c)) cout<<1;
        else cout<<0;
    }
    cout<<endl;
}
int main(){
    setup();
    int cmp=0;
    for(int i=1; i<=n; i++){
        if(!v[i]){ dfs(i, cmp); cmp++; }
    }
    queries();
return 0;
}
