#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e10
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        ll n; cin>>n;
        ll a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        ll mx=0; ll mn=INF;
        for(int i=0; i<n; i++){
            if(a[i]!=-1){
                if((i==0 && a[i+1]==-1) || (i==n-1 && a[i-1]==-1)){
                     mx=max(mx, a[i]); mn=min(mn, a[i]);
                }
                else if (a[i+1]==-1 || a[i-1]==-1){
                    mx=max(mx, a[i]); mn=min(mn, a[i]);
                }
            }
        }
        ll k=(mx+mn)/2;
        replace(a, a + n, (ll)(-1), k);
        ll mval=0;
        for(int i=0; i<n-1; i++)
            mval=max(mval, abs(a[i]-a[i+1]));
        if(mn==INF)
            cout<<0<<" "<<0<<endl;
        else
            cout<<mval<<" "<<k<<endl;
    }
return 0;
}
