
#include<bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n);
		for(int i=0; i<n; i++) cin>>a[i];
		vector<array<int, 3>> ans;
		for(int i=0; i<n; i++){
				cout<<"a: ";
				for(int j:a) cout<<j<<" "; cout<<endl;
			int mn=1e9, index=-1;
			for(int j=i; j<n; j++){
				mn=min(mn, a[j]);
				if(a[j]==mn) index=j;
			}
			if(mn!=a[i]){
				cout<<"index mn of "<<i<<" is "<<index<<endl;
				ans.push_back({i+1, index+1, index-i}); // shift[i, index] such that index is at i now
				
				int tmp2=a[i];
				for(int j=i+1; j<=index; j++){
					int tmp1=a[j];
					a[j]=tmp2;
					tmp2=tmp1;
				}
				a[i]=tmp2;
				//reverse(a.begin()+i, a.begin()+index+1);

			}

		}	
		cout<<(int)(ans.size())<<endl;
		for(auto i:ans){
			cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
		}
	}
}

/*

4
2
2 1
3
1 2 1
4
2 4 1 3
5
2 5 1 4 3

*/
