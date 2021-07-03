#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int l,r; cin>>l>>r;
        if(2*l <= r){
            cout<<l<<" "<<2*l<<endl;
        }
        else
            cout<<"-1 -1"<<endl;
    }
return 0;
}
