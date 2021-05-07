#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    set<int> s;
    for(int i=0; i<n-1; i++){
        int u; cin>>u; s.insert(u);
    }
    for(int i=1; i<=n; i++){
        if(!s.count(i)){
            cout<<i<<endl; break;
        }
    }
return 0;
}
