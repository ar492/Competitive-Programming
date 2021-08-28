#include <bits/stdc++.h>
using namespace std;

int n;
int mod(int val){
    int m=val%n;
    return (m<0 ? m+n : m);
}
int main(){
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){ cin>>a[i]; a[i]=mod(a[i]); }
    for(int i=1; i<n; i++){ a[i]+=mod(a[i-1]); a[i]=mod(a[i]); }
    map<int, int> mp;
    mp.insert(pair<int, int>(0, 1)); // mod, freq
    long long ans=0;
    for(int i=0; i<n; i++){
        ans+=mp[a[i]];
        mp[a[i]]++;
    }
    cout<<ans<<endl;
return 0;
}
