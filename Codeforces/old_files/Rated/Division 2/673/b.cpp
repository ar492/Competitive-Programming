#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; ll T; cin>>n>>T;
        ll a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        vector<ll> ans(n);
        bool which=0;
        for(int i=0; i<n; i++){
            if(a[i]<T/2.0) ans[i]=1;
            else if (a[i]==T/2.0){
                ans[i]=(int)which;
                which=!which;
            }
        }
        for(int i:ans) cout<<i<<" "; cout<<endl;
    }
return 0;
}
