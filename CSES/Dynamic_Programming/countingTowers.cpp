#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1e9+7;

signed main(){
        cin.tie(0)->sync_with_stdio(0);
        int t; cin>>t;
        while(t--){
                int n; cin>>n;
                ll join[n]={0}, sep[n]={0};
                join[0]=sep[0]=1;
                for(int i=1; i<n; i++){
                        sep[i]=((sep[i-1]*4)+join[i-1])%mod;
                        join[i]=(join[i-1]*2+sep[i-1])%mod;
                }
                cout<<((sep[n-1]+join[n-1])%mod)<<'\n';
        }

     return 0;
}
