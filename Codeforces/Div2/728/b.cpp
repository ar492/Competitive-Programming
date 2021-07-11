#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<array<int, 2>> a(n+1); // <val, index>
		for(int i=1; i<=n; i++){
			cin>>a[i][0];
			a[i][1]=i;
		}
		sort(a.begin()+1, a.end());
		int ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n && a[i][0]*a[j][0]<=2LL*n+1LL; j++){
				ans+=(a[i][0]*a[j][0]==a[i][1]+a[j][1]);
			}
		}
		cout<<ans<<endl;
	}
}

