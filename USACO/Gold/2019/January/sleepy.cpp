
#include 			<bits/extc++.h> // stdc++
#define 			_ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
using namespace std;        using namespace __gnu_pbds;
#define ost tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int sz=2e5;
int n,p[sz],pos;
signed main(){_
       ifstream cin("sleepy.in");  ofstream cout("sleepy.out");
	cin>>n; pos=n-1;
	for(int i=0; i<n; i++) cin>>p[i];
	ost oset; oset.insert(p[pos]);
       while(pos>0 && p[pos]>p[pos-1]) oset.insert(p[--pos]);

	cout<<pos<<endl;
	for(int i=0; i<pos; i++){
              cout<<(oset.order_of_key(p[i])+pos-i-1)<<(i==pos-1 ? "" : " ");
              oset.insert(p[i]);
	}
}
