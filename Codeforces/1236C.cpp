#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n; cin>>n;
	map<int, vector<int>> labs;
	int cnt=1;
	for(int k=0; k<n; k++){
		if(k&1){
			for(int i=n; i>=1; i--){ 
			//	cout<<i<<(i==1 ? "\n" : " ");
				labs[i].push_back(cnt++);
			}
		}
		else{
			for(int i=1; i<=n; i++){
			//	cout<<i<<(i==n ? "\n" : " ");
				labs[i].push_back(cnt++);
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j:labs[i]) cout<<j<<" "; cout<<endl;
	}
}
