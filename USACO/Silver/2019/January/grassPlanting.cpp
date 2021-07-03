#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("planting.in"); ofstream cout("planting.out");
    int n; cin>>n;
    int m=0; vector<int> cc(n, 0);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v; u--; v--;
        cc[u]++; cc[v]++;
        m=max(m, max(cc[u], cc[v]));
    }
    cout<<m+1<<endl;

return 0;
}
