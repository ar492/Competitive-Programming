#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<ll> rates; //products / time
int n,t;

bool made(ll time){
    ll cnt=0;
    for(int i=0; i<n; i++){
        cnt+=time/rates[i];
        if(cnt>=t) return true;
    }
    return false;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>t;
    for(int i=0; i<n; i++){
        int u; cin>>u; rates.push_back(u);
    }

    ll lo=0, hi=1e18;
    ll res=0;
    while(lo<=hi){
        ll m=lo+(hi-lo)/2;
        if(made(m)){ res=m; hi=m-1; }
        else lo=m+1;
    }
    cout<<res<<endl;
return 0;
}
