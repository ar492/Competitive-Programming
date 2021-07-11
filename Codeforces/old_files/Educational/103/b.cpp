#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x),end(x)
#define sort(x) sort(all(x))

signed main(){
	cin.tie(0)->sync_with_stdio(0);
        int t; cin>>t;
        while(t--){
                int n,k; cin>>n>>k;
                vector<int> a(n+1, 0), p(n+1, 0);
                for(int i=1; i<=n; i++) cin>>a[i];
                for(int i=1; i<=n; i++) p[i]=p[i-1]+a[i];
                for(int i=n; i>=1; i--){
                        if(100*a[i]>k*p[i-1]){
                                a[i]=(100*a[i])/k+1
                        }
                }
        }
}

// actually read tips.txt
