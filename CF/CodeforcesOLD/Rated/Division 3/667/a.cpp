#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        int d=abs(a-b);
        int cnt=0;
        for(int i=10; i>=1; i--){
            cnt+=d/i; d-=(d/i)*i;
        }
        cout<<cnt<<endl;
    }

return 0;
}
