
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)(X.size())

const int sz=3e5;

signed main(){
	int t; cin>>t;
	while(t--){
		int n, k; cin>>n>>k;
		vector<int> pos[n+1], ans(n);
		for(int i=0; i<n; i++){
			int u; cin>>u; pos[u].push_back(i);
		}
		int cur=1;
		map<int, int> fc;
		for(int i=1; i<=n; i++){
			for(int j=0; j<min(sz(pos[i]), k); j++){
				ans[pos[i][j]]=cur++;
				fc[cur-1]++;
				if(cur>k) cur=1;
			}
		}
		for(int i=0; i<n; i++){
			cout<<"ans["<<i<<"] = "<<ans[i]<<endl;
		}
		int mn=1e9;
		for(auto i:fc) mn=min(mn, i.second);
		for(int &i:ans){
			if(fc[i]>mn){
				cout<<"i, fc["<<i<<"] = "<<i<<" "<<fc[i]<<endl;
				i=0; fc[i]--;
			}
			cout<<i<<" ";
		}
		cout<<endl;
	}	
}
