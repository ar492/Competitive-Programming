#include <bits/stdc++.h>
using namespace std;

struct room{
    int x; int id;
    bool operator<(room const& other) {
        return x < other.x;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n; room hotel[n];
    set<int> ids;
    for(int i=0; i<n; i++){
        cin>>hotel[i].x>>hotel[i].id;
        ids.insert(hotel[i].id);
    }
    sort(hotel, hotel+n);
    int mn=hotel[n-1].x-hotel[0].x;
    int l=0; int r=0;
    set<int> cid;//unique id's in the current window
    map<int,int> idcnt;//number of each id in current window
    idcnt[hotel[0].id]=1;
    while(r<n){
        if(cid.size()<ids.size()){
            r++;
            if(r<n){
                cid.insert(hotel[r].id);
                idcnt[hotel[r].id]++;
            }
        }
        else{
            idcnt[hotel[l].id]--;
            if(idcnt[hotel[l].id]==0)
                cid.erase(hotel[l].id);
            mn=min(mn, hotel[r].x-hotel[l].x);
            l++;
        }
    }
    cout<<mn<<endl;
return 0;
}
