#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a;
		for(int i=1; i<=n; i++) a.push_back(i);
		for(int i=1; i<n; i++) if(i&1) swap(a[i], a[i-1]);
		if((n&1) && n>1) swap(a[n-1], a[n-2]);
		for(int i=0; i<n; i++){
			cout<<a[i]<<(i==n-1 ? "\n" : " ");
		}
	}
}
