#include<bits/stdc++.h>
using namespace std;
#define int long long

const int sz=3e5+5;
int xors[sz];

signed main(){
	for(int i=1; i<sz; i++){
		xors[i]=xors[i-1]^i;
	}
	int t; cin>>t;
	while(t--){
		int a, b; cin>>a>>b;
		int ans=a+1;
		if(xors[a-1]==b){
			ans=a;
		}
		else if((xors[a-1]^b)==a){
			ans=a+2;
		}
		cout<<ans<<endl;
	}
}
