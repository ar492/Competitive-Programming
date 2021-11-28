

#include<bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		deque<int> d;
		for(int i=0; i<n; i++){
			int u; cin>>u;
			if(i==0){
				d.push_back(u);
			}
			else{
				if(d[0]>=u) d.push_front(u);
				else d.push_back(u);
			}
		}
		for(int i:d) cout<<i<<" ";cout<<endl;
	}
}
