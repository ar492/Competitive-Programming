#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<int> s;
        for(int i=0; i<n; i++){
            int _; cin>>_;
            s.insert(_);
        }
        cout<<(s.size()!=n ? "YES" : "NO")<<endl;
    }
return 0;
}
