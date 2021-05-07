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
    int n, m; cin>>n>>m;
    multiset<int> tk;
    for(int i=0; i<n; i++){
        int u; cin>>u;
        tk.insert(u);
    }
    //for(auto i:tk) cout<<i<<" "; cout<<endl;
    for(int i=0; i<m; i++){

        int mp; cin>>mp;
        auto it=tk.upper_bound(mp);
        if(it==tk.begin()){
            cout<<-1<<endl;
        }
        else{
            --it;
            cout<<(*it)<<endl;
            tk.erase(it);
        }
    }

return 0;
}
