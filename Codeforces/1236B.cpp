#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

int expo(int a, int b){
	if(a==0) return b==0;
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		b>>=1LL;
		a=(a*a)%mod;
	}
	return ans;
}

signed main(){
	int n, m; cin>>n>>m;
	cout<<expo(expo(2, m)-1, n)<<endl;
}
