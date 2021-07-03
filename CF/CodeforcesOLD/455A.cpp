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
    ll n; cin>>n;
    ll a[(ll)1e5+2]={0}; // number * numOccurences
    ll m=0;
    for(ll i=0; i<n; i++){
        ll u; cin>>u; a[u]++;
        m=max(m,u);
    }
    for(ll i=0; i<=m; i++){
        a[i]*=i;
    }
    ll dp[m+3]; dp[0]=0; dp[1]=0;
    for(ll i=2; i<m+2; i++){
        dp[i]=max(a[i-1]+dp[i-2], dp[i-1]);
    }
    cout<<dp[m+1]<<endl;

return 0;
}
