#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;

int expo(int a, int b){
        int m=1, ans=1;
        for(int i=0; i<=29; i++){
                m*=(m==1 ? a : m);
                m%=mod;
                if(b & (1<<i)){
                        ans*=m;
                        ans%=mod;
                }
        }
        if(b==0) return 1;
        return((a==0) ? 0 : ans);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
        int n; cin>>n;
        while(n--){
                int a, b, c; cin>>a>>b>>c;
               // int x=expo(b, c)%mod;
                cout<<expo(a, expo(b, c))<<endl;
        }
}

// actually read tips.txt

/*

2
2 4
5 3

*/
