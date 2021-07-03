#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
int n,m;
vector<pair<ll, ll>> intervals;
bool placed(ll d){//O(n)
    ll prev=-1e18;
    int cnt=0;
    for (auto& i : intervals) {
        while (max(prev + d, i.f) <= i.s) {
            prev=max(prev + d, i.f);
            cnt++;
            if (cnt>=n) break;
        }
        if (cnt>=n) break;
    }
    return (cnt>=n);
}
int main(){
    ifstream cin("socdist.in"); ofstream cout("socdist.out");
    cin>>n>>m;
    intervals.resize(m);
    for(int i=0; i<m; i++) cin>>intervals[i].f>>intervals[i].s;
    sort(intervals.begin(), intervals.end()); //sorts by first value of pair
    //(intervals are non-overlapping so its ok)
    ll l=1; ll r=1e18;
    ll d;
    while(l<=r){//O(log(n))
        ll m=(l+r)/2;
        if(placed(m)){
            d=m; l=m+1;
        }
        else r=m-1;
    }
    cout<<d<<endl;
    return 0;
}
