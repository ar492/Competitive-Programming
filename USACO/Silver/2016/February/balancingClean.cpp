#include <bits/stdc++.h>
using namespace std;

struct pt{
    int x; int y;
};
bool c1(pt a, pt b){
    return(a.x<b.x);
}
bool c2(pt a, pt b){
    return(a.y>b.y);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("balancing.in"); ofstream cout("balancing.out");
    int n; cin>>n; pt cx[n], cy[n];
    for(int i=0; i<n; i++){
        cin>>cx[i].x>>cx[i].y;
        cy[i]=cx[i];
    }
    sort(cx, cx+n, c1); sort(cy, cy+n, c2);
    int mn=1e9;
    for(int i=0; i<n; i++){ // sweep top to bottom (decrease y, presorted).
        int y=cy[i].y+1;
        int above=0; int below=0;
        for(int j=0; j<n; j++){
            (cy[j].y>y) ? above++ : below++;
        }
        int tl=0; int bl=0; int br=below; int tr=above;
        for(int j=0; j<n; j++){// sweep left to right (increase x)
            int x=cx[j].x-1;
            while(x==cx[j].x-1 && j<n){
                if(cx[j].y<y){bl++; br--;}
                else if(cx[j].y>y){tl++; tr--;}
                j++;
            } j--;
            mn=min(mn, max({tl, bl, br, tr}));
        }
        while(y-1==cy[i].y && i<n) i++;
        i--;
    }
    cout<<mn<<endl;
return 0;
}
