#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--){
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a, a+n);
        int cnt=0;
        for(int i=1; i<n; i++){
            cnt+=(k-a[i])/a[0];
        }
        cout<<cnt<<endl;

    }
return 0;
}
