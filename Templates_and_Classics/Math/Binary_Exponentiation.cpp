// https://cses.fi/problemset/task/1095/

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int m=1e9+7;

int expo(int a, int b){
	if(a==0) return b==0;
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%m;
		b>>=1LL;
		a=(a*a)%m;
	}
	return ans;
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
