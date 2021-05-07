#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x; cin>>n>>x;
    long long a[n+1]; a[0]=0;
    for(int i=0; i<n; i++) cin>>a[i+1];
    for(int i=1; i<n+1; i++) a[i]+=a[i-1];
    map<long long, int> mp;
    long long ans=0;
    for(long long i:a){
        ans+=mp[i-x];
        mp[i]++;
    }
    cout<<ans<<endl;
return 0;
}
