#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef long long ll;
using namespace std;

struct cow{
    int x; int id;
    bool operator<(cow const& other) {
        return x < other.x;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("inp.txt");
    int n; cin>>n; cow line[n]; //cout<<"n is "<<n<<endl;
    set<int> ids;
    for(int i=0; i<n; i++){
        cin>>line[i].x>>line[i].id;
        //cout<<"inserting "<<line[i].x<<" "<<line[i].id<<endl;
        ids.insert(line[i].id);
    }
    sort(line, line+n);
   // cout<<"print cows"<<endl;
   // for(cow c:line){
   //     cout<<c.x<<" "<<c.id<<endl;
   // }
    int mn=line[n-1].x-line[0].x;
    int l=0; int r=0;
    set<int> cid;//current id
    map<int,int> idcnt;
    idcnt[line[0].id]=1;
    while(r<n){
        //cout<<"l,r: "<<l<<" "<<r<<endl;
        //cout<<"initial id display: "; for(int i:cid) cout<<i<<" ";cout<<endl;
        //cout<<"map display: "<<endl;
        //for(pair<int,int> i:idcnt){
        //    cout<<i.first<<" -> "<<i.second<<endl;
       // }
        if(cid.size()<ids.size()){
          //  cout<<"moving r up "<<endl;
            r++; if(r<n){cid.insert(line[r].id); idcnt[line[r].id]++;}
        }
        else{
            //cout<<cid.size()<<"<"<<ids.size()<<endl;
           // cout<<"moving l up"<<endl;
            idcnt[line[l].id]--;
            if(idcnt[line[l].id]==0) cid.erase(line[l].id);
            mn=min(mn, line[r].x-line[l].x);
            cout<<"min of "<<line[r].x<<" - "<<line[l].x<<endl;
            l++;
        }
       // cout<<endl;
    }
    cout<<mn<<endl;
return 0;
}
/*
10
1 3
10 3
9 2
6 3
8 3
5 3
2 2
7 2
3 3
4 1
*/
