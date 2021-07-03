#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("div7.in"); ofstream cout("div7.out");
    int n; cin>>n;
    long long a[n]; long long p[n];//input, prefix
    for(int i=0; i<n; i++) cin>>a[i];
    p[0]=a[0]%7;
    for(int i=1; i<n; i++) p[i]=(p[i-1]+a[i])%7;

    int occ[7]; // from 0 to 6 inclusive
    fill(occ, occ+7, -1);

    int mx=0;
    for(int i=0; i<n; i++){
        if(occ[p[i]]==-1) occ[p[i]]=i;
        else mx=max(mx, i-occ[p[i]]);
    }
    cout<<mx<<endl;
return 0;
}
