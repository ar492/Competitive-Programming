#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n,m; cin>>n>>m;
        int a[n]; int b[m];
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<m; i++)
            cin>>b[i];
        bool chk=false;
        int ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i]==b[j]){
                    ans=a[i]; chk=true; break;
                }
            }
        }
        if(chk==true)
            cout<<"YES"<<endl<<"1 "<<ans<<endl;
        else
            cout<<"NO"<<endl;
    }
return 0;
}
