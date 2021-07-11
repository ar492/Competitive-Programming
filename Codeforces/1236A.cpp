#include<bits/stdc++.h>
using namespace std;
#define int long long

int test(int a, int b){
	return(min(a, b/2));
}

signed main(){
	int t; cin>>t;
	while(t--){
		int a, b, c; cin>>a>>b>>c;
		int ans=0;
		ans+=test(b, c)*3;
		b-=test(b, c);
		c-=2*test(b, c);
		ans+=test(a, b)*3;
		cout<<ans<<endl;
	}
}

/*

1
3 4 5

*/
