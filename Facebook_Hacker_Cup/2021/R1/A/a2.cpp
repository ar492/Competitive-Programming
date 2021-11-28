
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()

const int mod=1e9+7;

signed main(){
	ifstream cin("weak_typing_chapter_2_input.txt");
	ofstream cout("o.txt");
	int t; cin>>t;
	for(int tc=1; tc<=t; tc++){
		int ans=0;
		int n; cin>>n;
		string s; cin>>s;
		cout<<"Case #"<<tc<<": ";
		vector<int> x, o;
		for(int i=0; i<n; i++){
			if(s[i]=='X') x.push_back(i);
			else if(s[i]=='O') o.push_back(i);
		}
		set<int> pos;
		char prev='F';
		for(int i=n-1; i>=0; i--){
			if(s.at(i)!=prev && s.at(i)!='F'){
				pos.insert(i);
				prev=s.at(i);
			}
		}
		for(int i=0; i<n; i++){
			if(!pos.count(i)) continue;
			if(s[i]=='X'){
				auto it=lower_bound(all(o), i+1);
				if(it==o.end()) continue;
				ans=(ans+(i+1)*(n-(*it)))%mod;
			}
			else if(s[i]=='O'){
				auto it=lower_bound(all(x), i+1);
				if(it==x.end()) continue;
				ans=(ans+(i+1)*(n-(*it)))%mod;
			}
		}
		cout<<ans<<endl;
	}
}
