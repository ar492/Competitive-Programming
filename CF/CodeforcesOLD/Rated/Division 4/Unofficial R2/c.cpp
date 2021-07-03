#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    int med;
    if(n%2==0) med=(a[n/2]+a[n/2-1])/2;
    else med=a[n/2];
    long long ans=0;
    for(int i:a){
        ans+=abs(i-med);
    }
    cout<<ans<<endl;
return 0;
}
