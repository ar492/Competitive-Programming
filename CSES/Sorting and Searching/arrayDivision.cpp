#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,k,x[(int)2e5];

int ok(ll sum){
    ll s=0, subs=1;
    for(int i=0; i<n; i++){
        if(x[i]>sum) return 0;
        if(x[i]+s > sum){  subs++; s=x[i]; }
        else s+=x[i];
    }

    return (subs<=k);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>x[i];
    }

    ll lo=1; ll hi=(ll)1e18;
    ll res;
    while(lo<=hi){
        ll m=(lo+hi)/2;
        if(ok(m)){ res=m; hi=m-1; }
        else lo=m+1;
    }
    cout<<res<<endl;


return 0;
}
