#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    int a[n]; int b[m];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    for(int x=0; x<=512; x++){
        bool c1=1;
        for(int ai:a){
            bool c2=0;
            for(int bj:b) if(((ai&bj)|x)==x){c2=1; break;}
            if(!c2) c1=0;
        }
        if(c1){
            cout<<x<<endl; break;
        }
    }
return 0;
}
