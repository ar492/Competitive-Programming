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

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //ifstream cin("pails.in"); ofstream cout("pails.out");
    int x,y,k,m; cin>>x>>y>>k>>m;
    if(x>y) swap(x,y); //x must be leq y
    set<int> s;
    s.insert(0); s.insert(x); s.insert(y);
    if(k>=2) s.insert(x+y);
    if(k>=3){
        for(int i=3; i<=k; i+=2){
            int t=ceil(i/2.0);
            if(t-1<=y) s.insert(t*x);
            else break;
        }
    }
    if(k>=(y/x)+2){
        s.insert(x-(y-(y/x)*x));
        if(k>=(y/x)+3)
            s.insert(y+(x-(y-(y/x)*x)));
        cout<<"inserted "<<x-(y-(y/x)*x)<<endl;
    }
    int mn=INF;
    for(int i:s){
        mn=min(mn, abs(i-m));
    }
    cout<<mn<<endl;
return 0;
}
