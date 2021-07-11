#include <bits/stdc++.h>
#define For(i,a,b) for (ll i = (a); i < (b); i++)
#define pb push_back
using namespace std;
typedef long long ll;

ifstream fin("input.txt");

struct point{
ll l; ll r;
};

int main(){
    int t; fin>>t;
    For(i, 0, t){
        ll n, x, m;
        fin>>n>>x>>m;
        vector <point> intervals;
        For(j, 0, m){
            point p; int temp; fin>>temp; p.l=temp; fin>>temp; p.r=temp; intervals.push_back(p);
        }
        For(j, 0, intervals.size()){
        ///    cout<<intervals[j].l<<" "<<intervals[j].r<<endl;
        }
        int index=-1;
        For(j, 0, intervals.size()){
            if(intervals[j].r>=x && intervals[j].l<=x){index=j;break;}
        }
       /// cout<<"index is "<<index<<endl;
       if(index==-1){cout<<1<<endl;}
       else{
        ll curleft=intervals[index].l; ll curright=intervals[index].r;
        For(j, index, intervals.size()){
            if(intervals[j].l<curleft && intervals[j].r>=curleft){curleft=intervals[j].l;}
            if(intervals[j].r>curright && intervals[j].l<=curright){curright=intervals[j].r;}
        }
        cout<<curright-curleft+1<<endl;
       }
    }
return 0;
}
