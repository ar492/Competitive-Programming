#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n,m,k; cin>>n>>m>>k;
    priority_queue<ll> apts, apps;
    for(ll i=0; i<n; i++){   ll u; cin>>u; apps.push(u);   }
    for(ll i=0; i<m; i++){   ll u; cin>>u; apts.push(u);   }
    ll cnt=0;
    while(apps.size()!=0 && apts.size()!=0){
        if(abs(apps.top()-apts.top())<=k){
            cnt++;
            apps.pop(); apts.pop();
        }
        else{
            if(apps.top()>apts.top()) apps.pop();
            else apts.pop(); // apps.top()<apts.top()
        }
    }
    cout<<cnt<<endl;
return 0;
}
