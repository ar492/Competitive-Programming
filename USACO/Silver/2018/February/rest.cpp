#include <bits/stdc++.h>
#define F first
#define S second
typedef long long LL;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("reststops.in","r",stdin);
    freopen("reststops.out","w",stdout);
    //set of pairs
    int L,N,Rf,Rb; cin>>L>>N>>Rf>>Rb;
    deque<pair<int, int>> path(N);// <location, ci>
    set<pair<int, int>, greater<pair<int, int>>> getmax; //<ci, location>
    //sorts g to l by ci, then by location.. this is good because
    //.. we want location to be as much as possible for tiebreaks
    for(int i=0; i<N; i++){
        cin>>path[i].F>>path[i].S;
        getmax.insert(pair<int, int>(path[i].S, path[i].F));
    }
    sort(path.begin(), path.end());

    long long ans=0; int prev=0;
    while(!getmax.empty()){
        ans+=(LL)(getmax.begin()->F)*(getmax.begin()->S - prev)*(Rf-Rb); //ci*x*(Rf-Rb)
        prev=getmax.begin()->S;
        while(!path.empty() && path[0].F<=prev){
            getmax.erase(pair<int, int>(path[0].S, path[0].F));
            path.pop_front();
        }
    }
    cout<<ans<<endl;

return 0;
}
