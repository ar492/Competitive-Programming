/*
#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);
    int t; cin>>t;
    while(t--){
        vector<pair<int, int>> normal, opposite;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int l,r; cin>>l>>r;
            normal.push_back({l, r});
            opposite.push_back({r, l});
        }
        int mx=0;
        for(auto i:normal)
            mx=max(mx, (int)normal.order_of_key({i.second+1, 0})-(int)opposite.order_of_key({i.first, 0}));
        cout<<n-mx<<endl;
    }
return 0;
}
*/

#pragma optimize("O3")
#pragma target("sse4")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less_equal<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        ordered_set normal, opposite;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int l,r; cin>>l>>r;
            normal.insert({l, r}), opposite.insert({r, l});
        }
        int mx=0;
        for(auto i:normal)
            mx=max(mx, (int)normal.order_of_key({i.second+1, 0})-(int)opposite.order_of_key({i.first, 0}));
        cout<<n-mx<<endl;
    }
    return 0;
}






