// https://cses.fi/problemset/task/1095/

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;

int expo(int a, int b){
        if(a==0 && b==0) return 1;
        int m=1, ans=1;
        while(b>0){
              m*=(m==1 ? a : m);    m%=mod;
              if(b&1) ans*=m;       ans%=mod;
              b/=2;
        }
        return(a ? ans : 0);
}

signed main(){
	      cin.tie(0)->sync_with_stdio(0);

        int n; cin>>n;
        while(n--){
                int a,b; cin>>a>>b;
                cout<<expo(a, b)<<endl;
        }

}
