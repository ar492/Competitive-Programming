#include<bits/stdc++.h>
using namespace std;

signed main(){ // try 111
	int t; cin>>t;
	while(t--){
		int x; cin>>x;
		string ans="NO";
	 	if(x<=10) cout<<ans<<endl;
		else if(x%11==0) cout<<"YES"<<endl;
		else if(x<111 && x%11!=0) cout<<ans<<endl;
		else{
			int num=111;
			for(int div=1; x-(div*num)>=0; div++){
				if((x-(div*num))%11==0 && (x-(div*num))/11>=div) ans="YES";
				if(div%10000==0) cout<<div<<endl;
			}
			cout<<ans<<endl;
		}	
	}
}
