
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)(X.size())

signed main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		map<char, int> freq;
		for(char i:s) freq[i]++;
		int two=0;
		int one=0;
		for(auto i:freq){
			if(i.second>1) two++;
			else if(i.second==1) one++;
		}
		cout<<(two+one/2)<<endl;
	}	
}
