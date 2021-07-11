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
        int n; string a,b; cin>>n>>a>>b;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]){
                ans.pb(i+1); ans.pb(1); ans.pb(i+1);
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<endl;
    }
return 0;
}
