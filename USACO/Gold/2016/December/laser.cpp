// O(n+n)

#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n, xl, yl, xb, yb;
map<int, set<int>> yx, xy;
map<pair<int, int>, int> d;
struct attribute{
        int x,y,dir;
};
signed main(){
        ifstream cin("lasers.in"); ofstream cout("lasers.out");
        cin.tie(0)->sync_with_stdio(0);
        cin>>n>>xl>>yl>>xb>>yb;
        for(int i=0; i<n; i++){
                int x,y; cin>>x>>y;
                xy[x].insert(y); yx[y].insert(x);
        }
        queue<attribute> q;
        q.push({xl, yl, 0}); // 1 is vertical, 2 is horizontal
        d[{xl, yl}]=0;
        while(!q.empty()){
                attribute a=q.front(); q.pop();
                set<pair<int, int>> vis;
                if( (a.dir==1 && a.y==yb) || (a.dir==2 && a.x==xb) || (a.dir==0 && (a.x==xb || a.y==yb))){
                        cout<<d[{a.x, a.y}]<<endl; return 0;
                }
                if(a.dir==0 || a.dir==1){
                        for(int x:yx[a.y]){
                                q.push({x, a.y, 2});
                                d[{x, a.y}]=1+d[{a.x, a.y}];
                                vis.insert({x, a.y});
                        }
                        if(a.dir==0){
                                for(int y:xy[a.x]){
                                        q.push({a.x, y, 1});
                                        d[{a.x, y}]=1+d[{a.x, a.y}];
                                        vis.insert({a.x, y});
                                }
                        }
                }
                else if(a.dir==2){
                        for(int y:xy[a.x]){
                                q.push({a.x, y, 1});
                                d[{a.x, y}]=1+d[{a.x, a.y}];
                                vis.insert({a.x, y});
                        }
                }
                for(auto i:vis){
                        xy[i.x].erase(i.y);
                        yx[i.y].erase(i.x);
                }
        }
        cout<<-1<<endl;
}

// actually read tips.txt
