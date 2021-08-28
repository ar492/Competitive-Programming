#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=998244353;
const int sz=2e5+5;
int p[sz];

signed main(){
	int x=1;
	for(int i=0; i<sz; i++){
		p[i]=x;
		x=(x*10)%mod;
	}
	int n; cin>>n;
	for(int i=1; i<=n; i++){
		if(i==n) cout<<"10\n";
		else{
			int edge=180*p[n-i-1];
			int corner=(n-i-1)*81*p[n-i-1];
			cout<<(edge+corner)%mod<<" ";
		}
	}
}

