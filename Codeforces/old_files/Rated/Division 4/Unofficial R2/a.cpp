#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin>>n>>k;
    set<int> s;
    for(int i=0; i<k; i++){
        int u; cin>>u;
        s.insert(u);
    }
    cout<<(s.size()==n-1 ? "YES" : "NO")<<endl;
return 0;
}
