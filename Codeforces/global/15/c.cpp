#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(X) (int)(X.size())
#define len(X) (int)(X.length())
#define all(X) (X).begin(), (X).end()


signed main(){
	int t; cin>>t;
	while(t--){
		int n, k; cin>>n>>k;
		vector<array<int, 2>> chords;
		set<int> unvis;
		for(int i=1; i<=2*n; i++) unvis.insert(i);
		for(int i=0; i<k; i++){
			int u, v; cin>>u>>v;
			chords.push_back({u, v});
			unvis.erase(u); unvis.erase(v);
		}
		vector<int> uv;
		for(int i:unvis) uv.push_back(i);
		for(int i=0; i<n-k; i++) chords.push_back({uv[i], uv[(i+n-k)%(2*n-k)]});
		for(auto &i:chords) if(i[0]>i[1]) swap(i[0], i[1]);
		int ans=0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				auto isect=[](auto a, auto b){
					return(a[0]>b[0] && a[0]<b[1] && (a[1]<b[0] || a[1]>b[1]));
				};
				ans+=(isect(chords[i], chords[j])+isect(chords[j], chords[i])>0);
			}
		}
		cout<<ans<<endl;
	}	
}
