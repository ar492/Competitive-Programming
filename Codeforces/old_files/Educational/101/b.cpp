#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int r[n];
        for(int i=0; i<n; i++){ cin>>r[i]; if(i!=0) r[i]+=r[i-1]; }
        int m; cin>>m;
        int b[m];
        for(int i=0; i<m; i++){ cin>>b[i]; if(i!=0) b[i]+=b[i-1]; }
        cout<<max({0, *max_element(r, r+n)+*max_element(b, b+m),  *max_element(r, r+n), *max_element(b, b+m)})<<endl;
    }
return 0;
}

/*

1
10
-2 -4 0 0 -4 3 -1 -1 -1 -1
4
1 4 4 -2

*/
