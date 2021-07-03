/*
#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);
	int t; cin>>t;
	while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        if(n<=2) cout<<0<<endl;
        else{
            long long ans=0;
            bool first=1;
            sort(a, a+n);
            int l=0, r=2;
            //while(r+1<n && a[r+1]-a[l]<=2) r++;
            while(r<n){
               // cout<<"c1: "<<l<<" "<<r<<endl;
                int OR=r;
                while(r+1<n && a[r+1]-a[l]<=2) r++;
                if(r-l<2) break;
                if(a[r]-a[l]<=2){
                    long long x=(r-l+1);
                    ans+=(x*(x-1)*(x-2)/6);
                }
               // cout<<"c2: "<<l<<" "<<r<<endl;
                if(!first && r-l>=2 && a[r]-a[l]<=2){
                    long long x=(OR-l+1);
                    ans-=x*(x-1)*(x-2)/6;
                }
                for(int i=l; i<n; i++){
                    if(a[i]!=a[l]){
                        l=i;
                        break;
                    }
                    if(i==n-1 && a[i]==a[l]) r=n+1;
                }
                //cout<<"c3: "<<l<<" "<<r<<endl;
                first=0;
            }
            //cout<<"answer : "<<ans<<endl;
            cout<<ans<<endl;
        }

	}
return 0;
}
/*
1
4
1 1 4 4

*/
