#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll a[n];
        ll mx=-INF-1; ll mn=INF+1;
        for(ll i=0; i<n; i++){
            ll u; cin>>u; a[i]=u; mx=max(mx, u); mn=min(mn,u);
        }
        for(ll i=0; i<n; i++)
            a[i]=mx-a[i];
        if(k%2==1){
            for(ll i:a) cout<<i<<" ";
        }
        else{
            mx=-INF+1;
            for(ll i=0; i<n; i++){
                mx=max(mx, a[i]);
            }
            for(ll i:a) cout<<mx-i<<" ";
        }
        cout<<endl;
    }
return 0;
}
