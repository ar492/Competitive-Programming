#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> a[5001];
bool v[5001];
int n,q;
int cnt=0;
void dfs(int node, int r){
    v[node]=1;
    cnt++;
    for(auto i:a[node]){
        if(!v[i.first] && i.second>=r){
            dfs(i.first, r);
        }
    }
}
int main(){
    ifstream cin("mootube.in"); ofstream cout("mootube.out");
    cin>>n>>q;
    for(int i=0; i<n-1; i++){
        int p,q,r; cin>>p>>q>>r;
        a[p].push_back({q, r});
        a[q].push_back({p, r});
    }
    for(int i=0; i<q; i++){
        int r, node;
        cin>>r>>node;
        dfs(node, r);
        cout<<cnt-1<<endl;
        cnt=0;
        fill(v, v+5001, 0);
    }

return 0;
}
