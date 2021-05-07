#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

signed main(){
        int n,k; cin>>n>>k; int a[n];
        ordered_set oset;
        for(int i=0; i<n; i++){
                int u; cin>>u; a[i]=u;
                oset.insert(u);
                if(i>=k) oset.erase(--oset.lower_bound(a[i-k]));
                if(i>=k-1) cout<<*oset.find_by_order((int)(k/2.0-0.1))<<endl;
        }
}
