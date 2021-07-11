#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n; int a[n];
    map<int, int> f;// <#, frequency>
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n, greater<int>());
    for(int i:a){
        f[i]++;
        if(f[i+1]==0){ f[i]--; f[i+1]++; i++;}
        else if(f[i]>1 && i!=1){ f[i]--; f[i-1]++; i--;}
    }
    int cnt=0;
    for(auto i:f) if(i.second>=1) cnt++;
    cout<<cnt<<endl;
    return 0;
}
