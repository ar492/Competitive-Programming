#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        long long x,y,k; cin>>x>>y>>k;
        long long ans=((k+y*k-1)/(x-1))+k;
        if((k+y*k-1)%(x-1)!=0) ans++;
        cout<<ans<<endl;
        //cout<<((k+y*k-1))<<" / "<<(x-1)<<" = "<<ceil((long long)(k+y*k-1)/(x-1))<<endl;

    }
return 0;
}
