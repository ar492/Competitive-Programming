#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin>>n>>q;
    int a[n+1]={0};
    pair<int,int> p[q];
    for(int i=0; i<q; i++){
        int l,r; cin>>l>>r; p[i]={l, r};
        for(int j=l; j<=r; j++) a[j]++;
    }
    int ans=0;
    //for(int i=1; i<=n; i++) cout<<a[i]<<" ";cout<<endl;
    for(int i=0; i<q; i++){
        int lfirst=p[i].first, rfirst=p[i].second; // interval of first painter to remove
        //cout<<"the first removal is "<<p[i].first<<" "<<p[i].second<<endl;
        int painted=0;
        int w[n+1]={0}; //with the first one removed
        for(int j=1; j<=n; j++){
            if(j>=lfirst && j<=rfirst)
                w[j]=a[j]-1;
            else w[j]=a[j];
            painted+=(w[j]>0);
        }
      //  cout<<"after removing it, there is painted "<<painted<<endl;
       // cout<<"field after removal: "<<endl;
       // for(int j=1; j<=n; j++) cout<<w[j]<<" "; cout<<endl;
        //removed first one
        int one[n+1]={0}; //section with one coat
        for(int j=1; j<=n; j++) one[j]=(w[j]==1);

        //make prefix from one
        for(int j=1; j<=n; j++) one[j]+=one[j-1];
        //iterate over second one to rmv, and rmv in const time
       // for(int j=0; j<=n; j++) cout<<one[j]<<" ";cout<<endl;
        for(int j=0; j<q; j++){
            if(j!=i)
                ans=max(ans, painted-(one[p[j].second]-one[p[j].first-1]));
           // cout<<"now ans is max("<<painted<<" - "<<(one[p[j].second]-one[p[j].first-1])<<endl;
        }
    }
    cout<<ans<<endl;
return 0;
}
