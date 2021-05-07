#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,q,x[(int)2e5+2];
signed main(){
        cin>>n>>q;
        for(int i=1; i<=n; i++){ cin>>x[i]; x[i]+=x[i-1]; }
        while(q--){
                int a,b; cin>>a>>b;
                cout<<x[b]-x[a-1]<<endl;
        }
        return 0;
}
