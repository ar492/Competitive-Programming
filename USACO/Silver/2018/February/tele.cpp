#include <bits/stdc++.h>
using namespace std;

int n; vector<pair<int,int>> hauls;
void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("teleport.in","r",stdin);
   //freopen("teleport.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++){
        int u,v; cin>>u>>v;
        hauls.push_back({u,v});
    }
}

double tempans;
bool ok(int y){//double? no
    vector<pair<int,int>> possible;
    for(auto i:hauls)
        if(abs(i.first)+(i.second < 0 ? abs(i.second) : 0) < abs(i.first-i.second))
            possible.push_back(i);
    if(possible.empty()) return false;
    double avg=0;
    for(auto i:possible) avg+=i.second;
    avg/=possible.size();

    tempans=0;
    for(auto i:hauls){
        tempans+=min(abs(i.second-i.first), abs(i.first)+abs(i.second-y));
    }
    for(auto i:possible)//better to not teleport than to teleport
        if(abs(i.first-i.second)<abs(i.first)+abs(i.second-y)) return false;
    return true;
}

int main(){
    setup();


    //choose y to the right of x=0
    //binary search over location of y

    double ans=1e14;
    {
        int lo=0, hi=(int)1e8;
        while(lo<=hi){
            int y=(lo+hi)/2;
            if(ok(y)){ ans=tempans; break; }
            else hi=y-1;
        }
    }//ans is now min ans if y to the right of x
    {
        int lo=(int)-1e8, hi=0;
        while(lo<=hi){
            int y=(lo+hi)/2;
            if(ok(y)){ ans=min(ans, tempans); break; }
            else hi=y-1;
        }
    }
    cout<<(long long)ans<<endl;

return 0;
}
