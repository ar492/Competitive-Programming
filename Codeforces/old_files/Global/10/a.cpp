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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<int> s;
        for(int i=0; i<n; i++){
            int u; cin>>u; s.insert(u);
        }
        if(s.size()==1) cout<<n<<endl;
        else cout<<1<<endl;
    }
return 0;
}
