#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0;
    cin>>t;
    for(int q=0; q<t; q++){
        ll n,r; cin>>n>>r;
        ll counter=1;
        /*
        for(ll k=2; k<=n; k++){
            if(n>=k+1)
                counter+=k;
            else
                counter++;
        }
        cout<<counter<<endl;
        */
        ll x=min(n-1, r);
        if(r<n)
            cout<<((x)*(x+1))/2<<endl;
        else
            cout<<1+((x)*(x+1))/2<<endl;
    }
    return 0;
}
