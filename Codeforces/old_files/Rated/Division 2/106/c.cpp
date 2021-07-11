#ifdef LOCAL
#include			<C:\\Users\\gbpol\\Desktop\\Useful\\cp.h>
#else
#include 			<bits/extc++.h> // stdc++
#endif
#define 			int long long
#define 			_ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
using namespace std;

#define pos first
#define cost second

signed main(){_


       int t; cin>>t;
       while(t--){
              int n; cin>>n;
              int ans=1e18, c[n+1]={0}, po[n+1]={0}, pe[n+1]={0};
              for(int i=1; i<=n; i++) cin>>c[i];
              pair<int, int> em[n+1], om[n+1];
              em[0]=om[0]={0, 1e18};
              for(int i=1; i<=n; i++){
                     em[i]=em[i-1]; om[i]=om[i-1];
                     pe[i]=pe[i-1]; po[i]=po[i-1];
                     if(i&1){
                            if(c[i]<om[i].cost){
                                   om[i].cost=c[i]; om[i].pos=i;
                            }
                            po[i]+=c[i];
                     }
                     else{
                            if(c[i]<em[i].cost){
                                   em[i].cost=c[i]; em[i].pos=i;
                            }
                            pe[i]+=c[i];
                     }
              }
              for(int i=2; i<=n; i++){
                     int ep=em[i].pos, op=om[i].pos;
                     int odd=po[i]-c[op]+(n-(i/2-(i%2==0)))*c[op];
                     int even=pe[i]-c[ep]+(n-i/2+1)*c[ep];
                     ans=min(ans, even+odd);
              }
              cout<<ans<<endl;
       }
}

/*

1
2
13 88


*/
