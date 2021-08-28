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
    ll t; cin>>t;
    for(ll i=0; i<t; i++){
        ll y,x; cin>>y>>x;//row y, col x
        ll n=max(x,y);
        ll s=n*n-n+1;
        if(n%2==0){
            if(y==n)
                cout<<y-x+s<<endl;
            else if (x==n)
                cout<<s-(x-y)<<endl;
        }
        else if(n%2==1){
            if(x==n)
                cout<<x-y+s<<endl;
            else if (y==n)
                cout<<s-(y-x)<<endl;
        }
    }
return 0;
}
