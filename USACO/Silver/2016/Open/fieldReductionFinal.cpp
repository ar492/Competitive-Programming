#include <bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int n; vector<pair<int,int>> pts;//all points
ll resmin=1e10; //answer

bool c0(pair<int,int> a, pair<int,int> b) {return a.F>b.F;} //mnX is last element
bool c1(pair<int,int> a, pair<int,int> b) {return a.F<b.F;} //mxX is last element
bool c2(pair<int,int> a, pair<int,int> b) {return a.S>b.S;} //mnY is last element
bool c3(pair<int,int> a, pair<int,int> b) {return a.S<b.S;} //mxY is last element

void compute(){
    ll smallx=5e4; ll largex=1; ll smally=5e4; ll largey=1;
    for(pair<ll,ll> p:pts){
        smallx=min(smallx, p.F); smally=min(smally, p.S);
        largex=max(largex, p.F); largey=max(largey, p.S);
    }
    resmin=min(resmin, (largex-smallx)*(largey-smally));
}

void rmv(int v){
    if(v==0) sort(pts.begin(), pts.end(), c0);
    if(v==1) sort(pts.begin(), pts.end(), c1);
    if(v==2) sort(pts.begin(), pts.end(), c2);
    if(v==3) sort(pts.begin(), pts.end(), c3);
    pts.pop_back();
}

int main(){
    ifstream cin("reduce.in"); ofstream cout("reduce.out");
    cin>>n;
    for(int i=0; i<n; i++){
        int u,v; cin>>u>>v; pts.push_back(pair<int,int>(u,v));
    }
    vector<pair<int,int>> ptscopy=pts;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++){
                rmv(i); rmv(j); rmv(k); compute();
                pts=ptscopy;//reset/put back the deletions
            }
    cout<<resmin<<endl;
return 0;
}
