#include<bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		int a=0, b=0, c=0;
		for(char i:s){
			if(i=='A') a++;
			if(i=='B') b++;
			if(i=='C') c++;
		}
		if(a+c==b){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
