

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)(X.size())
#define len(X) (int)(X.length())

char c;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<string> s(n);
		for(int i=0; i<n; i++) cin>>s[i];
		int mx=0;
		for(c='a'; c<='e'; c++){
			sort(all(s), [](const string &a, const string &b){
				return 2*count(all(a), c)-len(a)>2*count(all(b), c)-len(b);	
			});
			int sum=0;
			for(int i=0; i<n; i++){
				sum+=2*count(all(s[i]), c)-len(s[i]);
				if(sum<=0){
					mx=max(mx, i);
					break;
				}
			}
			if(sum>0) mx=n;
		}
		cout<<mx<<endl;
	}	
}
