#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (long long)1e15
#define MOD (int)(1e9+7)
#define endl "\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)cin>>a[i];
    sort(a, a+n);
    ll x=1; ll mn=INF;
    while((ll)pow(x, n-1)<=1e10){
        ll accum=0;
        for(int i=0; i<n; i++)
            accum+=abs(a[i]-pow(x, i));
        mn=min(mn, accum);
        x++;
    }
    cout<<mn<<endl;
return 0;
}
