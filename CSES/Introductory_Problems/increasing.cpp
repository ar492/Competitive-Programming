#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; int x; cin>>n>>x; ll runningMax=x;
    ll cost=0;
    for(int i=1; i<n; i++){
        ll u; cin>>u;
        if(u<runningMax)
            cost+=runningMax-u;
        runningMax=max(runningMax, u);
    }
    cout<<cost<<endl;
return 0;
}
