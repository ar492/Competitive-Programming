#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t; cin>>t;
	while(t--){
		int n, ans=0; cin>>n;
		vector<int> d(n);
		for(int i=0; i<n; i++) cin>>d[i];
		if(n==1){
			cout<<0<<endl; continue;
		}
		sort(d.begin(), d.end());
		for(int i=0; i<n-1; i++){
			ans+=(n-1-i)*d[i];
			ans-=(i+1)*d[i+1];
		}
		cout<<ans+d[n-1]<<endl;
	}
}

