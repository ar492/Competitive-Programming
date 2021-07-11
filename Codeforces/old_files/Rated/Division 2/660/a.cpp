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
        int n; cin>>n;
        if(n<31)
            cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            if(n==36)
                cout<<"5 6 10 15"<<endl;
            else if(n==40)
                cout<<"6 10 15 9"<<endl;
            else if (n==44)
                cout<<"6 10 15 13"<<endl;
            else
                cout<<6<<" "<<10<<" "<<14<<" "<<n-30<<endl;
        }
    }

return 0;
}
