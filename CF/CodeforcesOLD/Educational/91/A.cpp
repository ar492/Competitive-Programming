#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n;
        vector<int> p;
        for(int j=0; j<n; j++){
            int temp; cin>>temp;
            p.pb(temp);
        }
        bool c=false;
        for(int i=1; i<n-1; i++){
            if(p[i]>p[i-1] && p[i]>p[i+1]){
                cout<<"YES"<<endl<<i<<" "<<i+1<<" "<<i+2<<endl;
                c=true;
                break;
            }
        }
        if(!c)
            cout<<"NO"<<endl;
    }
return 0;
}


