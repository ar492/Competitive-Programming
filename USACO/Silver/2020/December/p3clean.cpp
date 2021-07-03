#include<bits/stdc++.h>
using namespace std;

int ans[1001];
vector<int> stops[1001]; //stops[i] contains the cows that 'i' stopped

struct cow{ int x, y, index; };
bool northcmp(cow a, cow b){ return a.x<b.x; }
bool eastcmp(cow a, cow b){ return a.y<b.y; }

int cnt=0;
void dfs(int node){
    for(int i:stops[node]){
        cnt++;
        dfs(i);
    }
}
bool stopped[1001]; //for collisions

int main(){
    int n; cin>>n;
    vector<cow> east, north;
    for(int i=0; i<n; i++){
        char d; int x, y;
        cin>>d>>x>>y;
        if(d=='N') north.push_back({x, y, i});
        else east.push_back({x, y, i});
    }
    sort(north.begin(), north.end(), northcmp);
    sort(east.begin(), east.end(), eastcmp);

    for(cow ea:east){
        for(cow no:north){
            if(stopped[no.index] or stopped[ea.index]) continue;
            if(ea.x<no.x and ea.y>no.y and no.x-ea.x<ea.y-no.y){ //east causes north to collide with it
                stops[ea.index].push_back(no.index);
                stopped[no.index]=1;
            }
            else if(ea.x<no.x and ea.y>no.y and no.x-ea.x>ea.y-no.y){ //north causes east to collide with it
                stops[no.index].push_back(ea.index);
                stopped[ea.index]=1;
            }
        }
    }
    for(int i=0; i<n; i++){
        dfs(i);
        ans[i]=cnt;
        cnt=0;
    }
    for(int i=0; i<n; i++)
        cout<<ans[i]<<"\n";

    return 0;
}
/*
3
E 0 1
N 2 0
N 3 0
*/
/*
3
N 2 3
N 1 0
E 0 4
*/
