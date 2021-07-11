#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

bool kb(int k, int i){ return((i&(1LL<<k))>0); }
int ip2(int i){ return ((1LL<<i)%mod); }

signed main() {
    int t; cin >> t;
    while(t--){
            int n; cin>>n;
            vector<int> b(60, 0);
            int x[n];
            for(int i=0; i<n; i++){
                    cin>>x[i];
                    for(int j=0; j<60; j++)
                            b[j]+=kb(j, x[i]);
            }

            int ans=0;
            for(int xj:x){
                    int ands=0, ors=0;
                    for(int i=0; i<60; i++){
                            if(kb(i, xj)){
                                    ands+=ip2(i)*b[i];
                                    ors+=ip2(i)*n;
                            }
                            else ors+=ip2(i)*b[i];
                            ands%=mod; ors%=mod;
                    }
                    ans+=(ands*ors)%mod;
                    ans%=mod;
            }
            cout<<ans<<endl;
    }
    return 0;
}
/*
1
7
19 15 6 8 3 7 5

1
2
1 7

*/
