#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;

void exe(){
        int n; cin>>n;
        int b[n];
        for(int i=0; i<n; i++) cin>>b[i];
        for(int i=0; i<n/2; i++){
            if(i==n/2-1 && n%2==0)cout<<b[i]<<" "<<b[n-i-1]<<endl;
            else cout<<b[i]<<" "<<b[n-i-1]<<" ";
        }
        if(n%2==1)
            cout<<b[n/2]<<endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);
    int t; cin>>t;
    while(t--){
        exe();

    }
return 0;
}
