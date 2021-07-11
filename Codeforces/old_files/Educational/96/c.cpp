#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<2<<endl<<n-1<<" "<<n<<endl;
        if(n>2){
            for(int i=n-2; i>=1; i--) cout<<i<<" "<<i+2<<endl;
        }
    }
return 0;
}
