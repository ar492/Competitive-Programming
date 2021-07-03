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
        ll n; cin>>n;
        ll a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        ll ans=0;
        for(int i=1; i<n; i++){
            if(a[i]-a[i-1]<0) ans+=a[i]-a[i-1];
        }
        cout<<abs(ans)<<endl;
    }
return 0;
}
