#include <bits/stdc++.h>
using namespace std;

void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
}

int main(){
    setup();
    int n; cin>>n;
    int s[n]; int u[n]; // sorted and unsorted
    for(int i=0; i<n; i++){ cin>>u[i]; s[i]=u[i]; }
    sort(s, s+n);
    int mn, mx;
    for(int i=0; i<n; i++) if(u[i]!=s[i]){ mn=i; break; }
    for(int i=n-1; i>=0; i--) if(u[i]!=s[i]){ mx=i; break; }

   int i, j;
   bool swapped;
   int cnt=0;
   while(1){
       swapped=false;
       for (i = 0; i < n-1; i++)
       {
            if (u[i] > u[i+1])
            {
               swap(u[i], u[i+1]);
               // cout<<"swap "<<i<<" and "<<i+1<<endl;
               swapped = true;
            }


         // IF no two elements were swapped by inner loop, then break
       }
       cnt++;
       if (swapped == false)
            break;
   }
   //for(int i:u) cout<<i<<" ";cout<<endl;
cout<<cnt<<endl;
    //cout<<mx-mn+1<<endl;
return 0;
}
