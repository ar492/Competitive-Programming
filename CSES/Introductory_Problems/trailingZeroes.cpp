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
    ll cnt=0;
    ll x=5;
    while(x<=n){
        cnt+=n/x;
        x*=5;
    }
    cout<<cnt<<endl;

return 0;
}
