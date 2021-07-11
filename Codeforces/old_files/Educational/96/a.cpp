#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==1 || n==2 || n==4) cout<<-1<<endl;
        else if(n%3==0) cout<<(n/3)<<" 0 0"<<endl;
        else if((n-2)%3==0) cout<<(n-5)/3<<" 1 0"<<endl;
        else cout<<((n-7)/3)<<" 0 1"<<endl;
    }
return 0;
}
