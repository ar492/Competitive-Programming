#include <bits/stdc++.h>
using namespace std;

struct point{
    bool x; //0 means departure, 1 means arrival
    int val;
};
bool cmp(point a, point b){
    return a.val<b.val;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<point> times;
    for(int i=0; i<n; i++){
        int a,d; cin>>a>>d;
        times.push_back({true, a});
        times.push_back({false, d});
    }
    sort(times.begin(), times.end(), cmp);
    int mx=0;
    int cur=0;
    for(point t:times){
        if(t.x) cur++;
        else cur--;
        mx=max(mx, cur);
    }
    cout<<mx<<endl;
return 0;
}
