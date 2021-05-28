// https://cses.fi/problemset/task/1095/

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;

int expo(int a, int b){
       return(b<=1?(b==1?a:1):((b&1?a:1)*expo((a*a)%mod,b/2))%mod);
}

signed main(){
       cin.tie(0)->sync_with_stdio(0);
       int n; cin>>n;
       while(n--){
               int a,b; cin>>a>>b;
               if(a+b==0) cout<<1<<endl;
               else cout<<expo(a, b)<<endl;
       }
}