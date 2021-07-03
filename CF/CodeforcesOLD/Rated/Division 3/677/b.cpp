#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        bool a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        int i=0;
        int ans=0;
        while(i<n && !a[i]) i++;
        while(i<n){
            while(i<n && a[i]) i++;
            int ploc=i;
            while(i<n && !a[i]) i++;
            if(i!=n && a[i]) ans+=i-ploc;
        }
        cout<<ans<<endl;
    }
return 0;
}
//0 1 1
