#include <bits/stdc++.h>
using namespace std;

void setup() {
    cin.tie (0)->sync_with_stdio (0);
    freopen ("stampede.in", "r", stdin);
    //freopen ("stampede.out", "w", stdout);
}

int main() {
    setup();
    int n;
    cin >> n;
    //use y for start, -y for end

    vector<pair<int,int>> events; // (time, y)
    for(int i=0; i<n; i++){
        int x,y,r; cin>>x>>y>>r;
        events.push_back({-r*(x+1), y}); //start
        events.push_back({-x*r, -y}); //end
    }
    sort(events.begin(), events.end());

    set<int> seen, current;
    for(int i=0; i<2*n; i++){
        int j=i;
        for(j; j<2*n && events[j].first==events[i].first; j++){//for the points of tranfer of time (segs)
            int y=events[j].second;
            if(y>0) current.insert(y);
            else current.erase(-y);
        }
        if(!current.empty()) seen.insert(abs(*current.begin()));
    }
    cout<<seen.size()<<endl;
    return 0;
}
