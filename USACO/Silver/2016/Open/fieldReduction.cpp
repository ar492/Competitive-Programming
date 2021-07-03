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

int n; vector<pair<int,int>> e[4]; //extremes
set<pair<int,int>> s; //all points
ll resmin=1e10; //answer

bool c1(pair<int,int> a, pair<int,int> b) {return a.F<b.F;} //mnX
bool c2(pair<int,int> a, pair<int,int> b) {return a.F>b.F;} //mxX
bool c3(pair<int,int> a, pair<int,int> b) {return a.S<b.S;} //mnY
bool c4(pair<int,int> a, pair<int,int> b) {return a.S>b.S;} //mxY

void compute(){
    ll smallx=5e4; ll largex=0; ll smally=5e4; ll largey=0;
    for(pair<ll,ll> p:s){
        smallx=min(smallx, p.F); smally=min(smally, p.S);
        largex=max(largex, p.F); largey=max(largey, p.S);
    }
    resmin=min(resmin, (largex-smallx)*(largey-smally));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("reduce.in"); //ofstream cout("reduce.out");
    cin>>n;
    vector<pair<int,int>> mnx, mxx, mny, mxy;
    for(int i=0; i<n; i++){
        pair<int,int> p;
        cin>>p.F>>p.S;
        mnx.pb(p); mxx.pb(p); mny.pb(p); mxy.pb(p);
        s.insert(p);
    }
    sort(mnx.begin(), mnx.end(), c1);
    sort(mxx.begin(), mxx.end(), c2);
    sort(mny.begin(), mny.end(), c3);
    sort(mxy.begin(), mxy.end(), c4);
    e[0]=mnx; e[1]=mxx; e[2]=mny; e[3]=mxy;
    set<pair<int,int>> os=s; //original set
    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            for(int k=j+1; k<4; k++){
                if(e[i][n-1]==e[j][n-1] || e[i][n-1]==e[k][n-1] || e[j][n-1]==e[k][n-1]){
                    if(e[i][n-1]==e[j][n-1]){
                        s.erase(e[i][n-1]); s.erase(e[k][n-1]);
                    }
                    else if(e[i][n-1]==e[k][n-1]){
                        s.erase(e[i][n-1]); s.erase(e[j][n-1]);
                    }
                    else if(e[j][n-1]==e[k][n-1]){
                        s.erase(e[j][n-1]); s.erase(e[i][n-1]);
                    }
                    for(int q=0; q<4; q++){
                        pair<int,int> p=e[q][e[q].size()-1];
                        s.erase(p);
                        compute();
                        s.insert(p);
                    }
                }
                else{
                    s.erase(e[i][n-1]); s.erase(e[j][n-1]); s.erase(e[k][n-1]);
                    compute();
                }
                s=os;
            }
        }
    }
    cout<<resmin<<endl;
return 0;
}
