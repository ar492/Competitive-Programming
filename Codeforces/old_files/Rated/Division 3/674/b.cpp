#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        bool ans=false;
        int a,b,c,d;
        for(int i=0; i<n; i++){
            cin>>a>>b>>c>>d; if(b==c) ans=true;
        }
        cout<<((ans && m%2==0) ? "YES" : "NO")<<endl;
    }
return 0;
}
