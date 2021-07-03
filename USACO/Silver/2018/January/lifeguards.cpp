#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct point{
    int id; bool isStart; int time; //sort by time
    bool operator<(point const& other) { return (time<other.time); }
};

vector<point> events; int N;
void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    cin>>N;
    for(int i=0; i<N; i++){
        int u,v; cin>>u>>v;
        events.push_back({i, true, u}); //start
        events.push_back({i, false, v}); //end
    }
    sort(events.begin(), events.end());
}
int unionfind(vector<point> e){
    int ans=0; int x=0;
    int prevloc;
    for(point p:e){
        if(x>0) ans+=p.time-prevloc;
        prevloc=p.time;
        x+=(p.isStart ? 1 : -1);
    }
    return ans;
}

int main(){
    setup();
    map<int, pair<int, int>> ids; // id -> <time as solo guard, solo starttime> pending ids
    int mn=1e9; // min solo contribution by some interval
    for(point p:events){
        if(p.isStart){
            if(ids.size()==1)
                (*ids.begin()).S.F += p.time-(*ids.begin()).S.S;
            ids.insert({p.id, {0, p.time}});//braces only viable in C++11
        }
        else{
            if(ids.size()==1) ids[p.id].F+=(p.time-ids[p.id].S);
            mn=min(mn, ids[p.id].F);
            ids.erase(p.id);
            if(ids.size()==1) (*ids.begin()).S.S=p.time;
        }
    }
    cout<<(unionfind(events)-mn)<<endl;
return 0;
}
