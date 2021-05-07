#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x; cin>>n>>x;
    pair<int,int> a[n];
    for(int i=0; i<n; i++){ cin>>a[i].first; a[i].second=i+1; }
    sort(a, a+n);
    int l=0, r=n-1;
    while(r<n && l<r){
        if(a[l].first+a[r].first<x) l++;
        else if(a[l].first+a[r].first>x) r--;
        else{ cout<<a[l].second<<" "<<a[r].second<<endl; return 0; }
    }
    cout<<"IMPOSSIBLE"<<endl;
return 0;
}
