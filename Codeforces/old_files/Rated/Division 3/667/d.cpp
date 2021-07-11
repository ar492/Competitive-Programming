#include <bits/stdc++.h>
using namespace std;

int sum(long long n){
    int s=0;
    while(n>0){
        s+=n%10;
        n/=10;
    }
    return s;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        long long n, s; cin>>n>>s;
        int moves=0;
        while(sum(n%10)>s){
            moves+=10-n%10;
            n+=10-n%10;
        }
        cout<<moves<<endl;
    }
return 0;
}
