#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<int> x;
        int a[n]; for(int i=0; i<n; i++){ cin>>a[i]; x.insert(a[i]); }
        if(x.size()==1) cout<<-1<<endl;
        else{
            int mx=*max_element(a, a+n);
            for(int i=0; i<n-1; i++){
                if(a[i]==mx && a[i+1]<mx){ cout<<i+1<<endl; break; }
                else if(a[i]<mx && a[i+1]==mx){ cout<<i+2<<endl; break; }
            }
        }
    }
return 0;
}
