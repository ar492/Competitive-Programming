#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("lemonade.in","r",stdin);
    freopen("lemonade.out","w",stdout);
    int n; cin>>n;
    vector<int> w(n);
    for(int i=0; i<n; i++) cin>>w[i];
    sort(w.begin(), w.end());
    for(int i=0; i<n; i++)
        if(n-i-1<=w[i]){ cout<<n-i<<endl; break; }

return 0;
}
