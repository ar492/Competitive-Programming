#ifdef LOCAL
       #include "C:\\Users\\gbpol\\Desktop\\Useful\\cp.h"
#else
       #include <bits/stdc++.h>
#endif
#define int long long
using namespace std;

const int sz=2e5+3;
int n,q, x[sz], p[sz];

signed main(){
       cin.tie(0)->sync_with_stdio(0);
       cin>>n>>q;
       for(int i=1; i<=n; i++) cin>>x[i];

       p[1]=x[1];
       for(int i=2; i<=n; i++) p[i]=(p[i-1]^x[i]);

       while(q--){
              int a,b; cin>>a>>b;
              what(p[b]);
       }
}
