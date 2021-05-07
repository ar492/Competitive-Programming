#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    int k[n];
    for(int i=0; i<n; i++) cin>>k[i];
    int l=0, r=0;
    map<int, int> f;
    int mx=0;
    while(r<n){
        while(r<n && f[k[r]]==0){
            f[k[r]]++; r++;
        }
        f[k[r]]--;
        for(auto i:f) cout<<i.first<<" "<<i.second<<endl;
        cout<<"for l,r: "<<l<<" "<<r<<endl;
        mx=max(mx, r-l);
        l++;
    }
    cout<<mx<<endl;
return 0;
}
