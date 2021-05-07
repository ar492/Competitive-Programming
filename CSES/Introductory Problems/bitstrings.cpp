#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    ll ans=1;
    for(int i=0; i<n; i++){
        ans*=2;
        ans=ans%MOD;
    }
    cout<<ans<<endl;
return 0;
}
