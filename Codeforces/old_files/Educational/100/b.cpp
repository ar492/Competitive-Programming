#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        long long s=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            s+=a[i];
        }
        long long c1=0, c2=0;
        for(int i=0; i<n; i++){
            c1+=(i&1 ? 1 : a[i]);
        }
        for(int i=1; i<n; i++){
            c2+=(i&1 ? a[i] : 1);
        }
        if(c2<<1<=s){
            for(int i=0; i<n; i++){
                if(!(i&1)){
                    if(i==n-1) cout<<a[i]<<endl;
                    else cout<<a[i]<<" ";
                }
                else{
                    if(i==n-1) cout<<1<<endl;
                    else cout<<1<<" ";
                }
            }
        }
        else{
            for(int i=0; i<n; i++){
                if((i&1)){
                    if(i==n-1) cout<<a[i]<<endl;
                    else cout<<a[i]<<" ";
                }
                else{
                    if(i==n-1) cout<<1<<endl;
                    else cout<<1<<" ";
                }
            }
        }

    }
    return 0;
}
