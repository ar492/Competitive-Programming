#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int i=0; i<t; i++){
        int x,y,z; cin>>x>>y>>z;
        if(x==y && z<=x)
            cout<<"YES"<<endl<<x<<" "<<z<<" "<<z<<endl;
        else if (x==z && y<=x)
            cout<<"YES"<<endl<<y<<" "<<x<<" "<<y<<endl;
        else if (y==z && x<=y)
            cout<<"YES"<<endl<<x<<" "<<x<<" "<<y<<endl;
        else
            cout<<"NO"<<endl;
    }
return 0;
}


