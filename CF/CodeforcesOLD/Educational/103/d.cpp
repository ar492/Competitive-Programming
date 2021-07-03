#include<bits/stdc++.h>
#define ll long long
#define l first
#define r second
using namespace std;

// 0 = invalid, 1 = L, 2 = R

signed main(){
	cin.tie(0)->sync_with_stdio(0);
       int t; cin>>t;
       while(t--){
              int n; cin>>n;
              map<int, pair<int, int>> g;
              int L[n+1], R[n+1];
              for(int i=0; i<n; i++){
                     char c; cin>>c;
                     g[i].r=(c=='L' ? 1 : 2);
                     g[i+1].l=(c=='L' ? 1 : 2);
              }
              n++;
              for(int i=0; i<n; i++){
                     int oi=i;
                     while(i<n && g[i].r+g[i+1].r==3) i++;
                     i+=(oi!=i);
                     for(int j=oi; j<=i; j++)
                            R[j]=(g[j].r==2 ? max(i-j,1) : 0);
              }
              for(int i=n-1; i>=0; i--){
                     int oi=i;
                     while(i>0 && g[i].l+g[i-1].l==3) i--;
                     i-=(oi!=i);
                     for(int j=i; j<=oi; j++)
                            L[j]=(g[j].l==1 ? max((j-i),1) : 0);
              }
              for(int i=0; i<n; i++){
                     int ans=1;
                     if(R[i])
                            ans=max(ans, 1+R[i]+((R[i]&1) ? L[i] : 0));
                     if(L[i])
                            ans=max(ans, 1+L[i]+((L[i]&1) ? R[i] : 0));
                     cout<<ans<<endl;
              }
       }
}


