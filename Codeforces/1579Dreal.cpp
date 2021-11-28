

#include<bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		set<array<int, 2>> x; // val, index
		for(int i=0; i<n; i++){
			int u; cin>>u;
			x.insert({u, i});
		}
		vector<array<int, 2>> ans;
		while(x.size()>=2){
			auto i=*x.rbegin();
			x.erase(*x.rbegin());
			auto j=*x.rbegin();
			x.erase(*x.rbegin());
			if(i[0] && j[0]){
				i[0]--;
				j[0]--;
				ans.push_back({i[1], j[1]});
			}
			if(i[0]) x.insert(i);
			if(j[0]) x.insert(j);
		}
		cout<<(int)(ans.size())<<endl;
		for(auto i:ans){
			cout<<i[0]+1<<" "<<i[1]+1<<endl;
		}
	}
}
